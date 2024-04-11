#include<bits/stdc++.h>
//#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=100007;
const int bufsz=2500;

struct info{
    int l,r,x,k,idx;
    friend bool operator<(info l,info r){
        if (l.l/bufsz<r.l/bufsz) return 1;
        if (l.l/bufsz==r.l/bufsz&&l.r/bufsz<r.r/bufsz) return 1;
        if (l.l/bufsz==r.l/bufsz&&l.r/bufsz==r.r/bufsz&&l.x<r.x) return 1;
        return 0;
    }
};

struct upd{
    int x,val,pval;
};

int n,m;
int a[maxn],b[maxn];
int cnt[maxn],tot[maxn];
int prv[maxn],nxt[maxn];
info qry[maxn];
upd up[maxn];
int ans[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    int ml=0,mr=0;
    rep(i,n) cin>>a[i];
    rep(i,n) b[i]=a[i];
    rep(i,m){
        int op;
        cin>>op;
        if (op==1){
            cin>>qry[ml].l>>qry[ml].r>>qry[ml].k;
            qry[ml].l--;
            qry[ml].x=mr;
            qry[ml].idx=ml;
            ml++;
        }
        else{
            cin>>up[mr].x>>up[mr].val;
            up[mr].x--;
            up[mr].pval=b[up[mr].x];
            b[up[mr].x]=up[mr].val;
            mr++;
        }
    }
    nxt[n]=n+1, prv[n+1]=n;
    auto addlink=[&](int u){
        nxt[prv[n+1]]=u;
        prv[u]=prv[n+1];
        nxt[u]=n+1;
        prv[n+1]=u;
    };
    auto remvlink=[&](int u){
        nxt[prv[u]]=nxt[u];
        prv[nxt[u]]=prv[u];
    };
    auto add=[&](int u){
//        cerr<<"ADD: "<<u<<endl;
        tot[cnt[u]]--;
        if (!tot[cnt[u]]){
            remvlink(cnt[u]);
        }
        if (!tot[++cnt[u]]){
            addlink(cnt[u]);
        }
        tot[cnt[u]]++;
    }; 
    auto remv=[&](int u){
//        cerr<<"REMOVE: "<<u<<endl;
        tot[cnt[u]]--;
        if (!tot[cnt[u]]){
            remvlink(cnt[u]);
        }
        if (!tot[--cnt[u]]){
            addlink(cnt[u]);
        }
        tot[cnt[u]]++;
    };
    auto solve=[&](int k){
        int x=n;
        vi val;
        val.clear();
        while (1){
            x=nxt[x];
            if (x<n) val.pb(x);
            else break;
        }
        sort(range(val));
        int l=0,r=0,ans=1e9,sum=0;
        while (l<sz(val)){
            while (r<sz(val)&&sum<k) sum+=tot[val[r++]];
            if (sum>=k) ans=min(ans,val[r-1]-val[l]);
            sum-=tot[val[l++]];
        }
        if (ans==1e9) return -1;
        return ans;
    };
    sort(qry,qry+ml);
    int cl=0,cr=0,cx=0;
    rep(i,ml){
 //       cerr<<"QUERY: "<<qry[i].idx<<" "<<qry[i].l<<" "<<qry[i].r<<" "<<qry[i].k<<" "<<qry[i].x<<endl;
        while (cx<qry[i].x){
            int pos=up[cx].x;
            if (cl<=pos&&pos<cr) remv(a[pos]);
            a[pos]=up[cx].val;
            if (cl<=pos&&pos<cr) add(a[pos]);
            cx++;
        }
        while (cx>qry[i].x){
            cx--;
            int pos=up[cx].x;
            if (cl<=pos&&pos<cr) remv(a[pos]);
            a[pos]=up[cx].pval;
            if (cl<=pos&&pos<cr) add(a[pos]);
        }
        while (cr<qry[i].r){
            add(a[cr++]);
        }
        while (cl>qry[i].l){
            add(a[--cl]);
        }
        while (cl<qry[i].l){
            remv(a[cl++]);
        }
        while (cr>qry[i].r){
            remv(a[--cr]);
        }
        ans[qry[i].idx]=solve(qry[i].k);
    }
    rep(i,ml) cout<<ans[i]<<"\n";
    return 0;
}