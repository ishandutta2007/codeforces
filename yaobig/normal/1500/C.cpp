#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi a[maxn+5],b[maxn+5];
int br[maxn+5][maxn+5],cnt[maxn+5];
bool mark[maxn+5],ok[maxn+5];

int ctrl;

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) a[i].resize(m+1);
    rep(i,1,n) b[i].resize(m+1);
    rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);
    rep(i,1,n) rep(j,1,m) scanf("%d",&b[i][j]);
    rep(j,1,m) rep(i,1,n-1) if(b[i][j]>b[i+1][j]) br[j][i]=1,cnt[j]++;
 
    queue<int> q;
    rep(j,1,m) if(cnt[j]==0) q.push(j);
    vi ans;
    while(q.size())
    {
        int now=q.front(); ans.pb(now);
        q.pop();
        rep(i,1,n-1) if(ok[i]==0 && b[i][now]<b[i+1][now])
        {
            ok[i]=1;
            rep(j,1,m) if(cnt[j])
            {
                if(br[j][i]==1)
                {
                    br[j][i]=0;
                    if(--cnt[j]==0)
                    {
                        mark[j]=1;
                        q.push(j);
                    }
                }
            }

        }
    }
    reverse(ans.begin(),ans.end());
    for(auto j: ans) 
    {
        ctrl=j;
        stable_sort(a+1,a+n+1,[](const vi &x,const vi &y){return x[ctrl]<y[ctrl];});
    }
    int fl=1;
    rep(i,1,n) rep(j,1,m) if(a[i][j]!=b[i][j]) fl=0;
    if(fl)
    {
        int N=ans.size();
        printf("%d\n",N);
        rep(i,0,N-1) printf("%d%c",ans[i]," \n"[i==N-1]);
    }
    else puts("-1");
    return 0;
}