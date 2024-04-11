#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=2007;
int n,s,m,k;
int a[maxn],sum[maxn],dp[maxn][maxn],f[maxn][maxn];
PI seg[maxn];
vector<PI> sa;

bool ck(int val,int fuck){
    for (int i=1;i<=n;++i){
        sum[i]=(a[i]<=val);
    }
    for (int i=1;i<=n;++i) sum[i]+=sum[i-1];
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    int k=1;
    for (int i=1;i<=sa.size();++i){
        while (k<i&&sa[i-1].F>sa[k-1].S) k++;
        for (int j=1;j<=i;++j){
            dp[i][j]=max(dp[k][j-1]+sum[sa[i-1].S]-sum[sa[k-1].S],f[k-1][j-1]+sum[sa[i-1].S]-sum[sa[i-1].F-1]);
            f[i][j]=max(f[i-1][j],dp[i][j]);
        }
    }
    int ret=0;
    for (int i=0;i<=m;++i){
        ret=max(ret,f[sa.size()][i]);
    }
//    cout<<val<<" "<<ret<<endl;
    return (ret>=fuck);
}

int ms(int l,int r){
    if (l==r) return l;
    int md=(l+r)>>1;
    if (ck(md,k)) return ms(l,md);
    else return ms(md+1,r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>s>>m>>k;
    rep1(i,n) cin>>a[i];
    rep1(i,s) {cin>>seg[i].F>>seg[i].S; seg[i].S=-seg[i].S;}
    sort(seg+1,seg+s+1);
    rep1(i,s){
        bool fg=true;
        for (int j=1;j<i;++j){
            if (seg[i].S>=seg[j].S) fg=false;
        }
        if (fg) sa.pb({seg[i].F,-seg[i].S});
    }
 /*   for (auto c:sa){
        cout<<c.F<<" "<<c.S<<endl;
    }*/
    int ret=ms(1,1e9+1);
    if (ret>1e9) ret=-1;
    cout<<ret<<endl;
    return 0;
}