#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 10000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
int id[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        int sum=0;
        rep(i,1,n) scanf("%d",&a[i]),sum+=a[i];
        if(sum%n!=0) {puts("-1"); continue;}
        sum/=n;
        vector<pair<pii,int> > ans;
        rep(i,2,n)
        {
            int r=a[i]%i;
            if(r)
            {
                int x=i-r;
                ans.pb(mp(mp(1,i),x));
                a[i]+=x;
                a[1]-=x;
            }
            int x=a[i]/i;
            ans.pb(mp(mp(i,1),x));
            a[i]-=x*i;
            a[1]+=x*i;
        }
        rep(i,2,n) ans.pb(mp(mp(1,i),sum));
        int N=ans.size();
        printf("%d\n",N);
        for(auto it: ans) printf("%d %d %d\n",it.FI.FI,it.FI.SE,it.SE);
    }
    return 0;
}