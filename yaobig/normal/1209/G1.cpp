#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5],l[maxn+5],r[maxn+5],cnt[maxn+5];

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,maxn) l[i]=inf,r[i]=0;
    rep(i,1,n)
    {
        chmin(l[a[i]],i);
        chmax(r[a[i]],i);
        cnt[a[i]]++;
    }
    int L=1,R=1;
    int ans=0;
    while(L<=n)
    {
        int mx=0;
        rep(i,L,R)
        {
            chmax(mx,cnt[a[i]]);
            chmax(R,r[a[i]]);
        }
        ans+=R-L+1-mx;
        L=R=R+1;
    }
    printf("%d\n",ans);
    return 0;
}