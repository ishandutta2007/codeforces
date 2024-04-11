#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int cnt[maxn+5];
int ava[maxn+5],sum[maxn+5];

int main()
{
    int CAS; scanf("%d",&CAS);
    while(CAS--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) cnt[i]=0;
        rep(i,1,n) ava[i]=1;
        rep(i,1,n) sum[i]=0;
        rep(i,1,n) {int x; scanf("%d",&x); cnt[x]++;}
        int MX=inf;
        rep(i,1,n) if(cnt[i]) MX=min(MX,cnt[i]);
        rep(i,1,n)
        {
            int X=cnt[i];
            rep(s,1,X+1)
            {
                int t=X/s;
                int r=X%s;
                if(r==0)
                {
                    sum[s]+=t;
                }
                else
                {
                    if(t+r>=s-1) sum[s]+=t+1;
                    else ava[s]=0;
                }
            }
        }
        int ans=inf;
        //rep(i,1,MX+1) printf("?? %d: %d %d\n",i,ava[i],sum[i]);
        rep(i,1,MX+1) if(ava[i]) ans=min(ans,sum[i]);
        assert(ans!=inf);
        printf("%d\n",ans);
    }
	return 0;
}