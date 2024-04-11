#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5][maxn+5];
vi r[maxn+5],c[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);
    rep(i,1,n) rep(j,1,m) r[i].pb(a[i][j]);
    rep(i,1,n) rep(j,1,m) c[j].pb(a[i][j]);
    rep(i,1,n)
    {
        sort(r[i].begin(),r[i].end());
        r[i].erase(unique(r[i].begin(),r[i].end()),r[i].end());
    }
    rep(i,1,m)
    {
        sort(c[i].begin(),c[i].end());
        c[i].erase(unique(c[i].begin(),c[i].end()),c[i].end());
    }
    rep(i,1,n) rep(j,1,m)
    {
        int M=r[i].size();
        int N=c[j].size();
        int x=lower_bound(r[i].begin(),r[i].end(),a[i][j])-r[i].begin()+1;
        int y=lower_bound(c[j].begin(),c[j].end(),a[i][j])-c[j].begin()+1;
        printf("%d%c",max(x,y)+max(M-x,N-y)," \n"[j==m]);
    }
    return 0;
}