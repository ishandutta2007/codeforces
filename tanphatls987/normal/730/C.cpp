#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
#define X first
#define Y second

const int N=5e3+10;
const ll inf=1e12;
int n,n1,q[N];
vector <ii> store[N];
vector <int> v[N],imp[N];
int p[N];
int lv[N];
int test;
ii need[N];
int ans[N];

struct BIT{
    ll b[N];
    void reset(){
        memset(b,0,sizeof(b));
    }
    void add(int x,ll val){
        while (x<=n1){
            b[x]+=val;
            x+=x&-x;
        }
    }
    ll get(int x){
        ll ans=0;
        while (x){
            ans+=b[x];
            x-=x&-x;
        }
        return ans;
    }
    int findfre(ll val){
        int pos=0;
        for(int i=int(log2(n1));i>=0;i--){
            int cur=pos+(1<<i);
            if (cur>n1) continue;
            if (val>b[cur]) val-=b[cur],pos=cur;
        }
        return pos+1;
    }
}cbit,nbit;
int BFS(int st){
    int top=1;
    q[1]=st;
    memset(lv,0,sizeof(lv));
    lv[st]=1;
    for(int i=1;i<=top;i++){
        int x=q[i];
        for(auto y:v[x]) if (!lv[y]){
            lv[y]=lv[x]+1;
            q[++top]=y;
        }
    }
    return top;
}
void prepare(){
    int m;
    scanf("%d%d",&n,&m);
    while (m--){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d",&m);
    while (m--){
        int pos,wei,pri;
        scanf("%d%d%d",&pos,&wei,&pri);
        p[++n1]=pri;
        store[pos].push_back(ii(pri,wei));
    }
    sort(p+1,p+n1+1);
    n1=unique(p+1,p+n1+1)-p-1;
    for(int i=1;i<=n;i++)
        for(auto &j:store[i]) j.X=lower_bound(p+1,p+n1+1,j.X)-p;
//    cout<<n1<<'\n';
//    for(int i=1;i<=n1;i++) cout<<p[i]<<" \n"[i==n1];
    scanf("%d",&test);
    for(int i=1;i<=test;i++){
        int pos;
        scanf("%d%d%d",&pos,&need[i].X,&need[i].Y);
        imp[pos].push_back(i);
    }
}
ll cal(ll val){
    if (nbit.get(n1)<val) return inf;
    int idx=nbit.findfre(val);
//    cout<<val<<"=>"<<idx<<" "<<nbit.get(idx-1)<<'\n';
    val-=nbit.get(idx-1);
    return cbit.get(idx-1)+val*p[idx];
}
void solve(){
    for(int st=1;st<=n;st++){
        int n2=BFS(st);
//        cout<<st<<" "<<n2<<'\n';
//        for(int i=1;i<=n2;i++) cout<<q[i]<<" \n"[i==n2];
        cbit.reset();
        nbit.reset();
        for(int i=1;i<=n2;){
            int ci=i;
            while (i<=n2&&lv[q[i]]==lv[q[ci]]){
                for(auto j:store[q[i]]){
//                        cout<<"?"<<j.X<<" "<<j.Y<<'\n';
                    cbit.add(j.X,1LL*p[j.X]*j.Y);
                    nbit.add(j.X,j.Y);
                }
                i++;
            }
            for(auto j:imp[st]) if (ans[j]==0){
//                cout<<st<<" "<<j<<" "<<need[j].X<<" "<<lv[q[ci]]<<" "<<cal(need[i].X)<<'\n';
                if (cal(need[j].X)<=need[j].Y) ans[j]=lv[q[ci]];
            }
        }
    }
    for(int i=1;i<=test;i++) printf("%d\n",ans[i]-1);
}
int main(){
    prepare();
    solve();
}