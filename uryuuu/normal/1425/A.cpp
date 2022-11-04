#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define flush fflush(stdout)
const double pi=acos(-1);
const int maxn=300010;
const ll Mod = 998244353;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll sum=0;
        if(n%2==0)
        {
            while(n>0)
            {
                if(n==4ll)
                {
                    sum=1ll*sum+3ll;
                    break;
                }
                if(n==1ll)
                {
                    sum=1ll*sum+1ll;
                    break;
                }
                if((n/2ll)%2ll==0)
                {
                    n=1ll*n-2ll;
                    sum=1ll*sum+1ll;
                }
                else
                {
                    n=1ll*n/2;
                    sum=1ll*sum+n;
                    n=1ll*n-1ll;
                }
            }
            printf("%lld\n",sum);
        }
        else
        {
            ll d=n;
            n=1ll*n-1ll;
            while(n>0)
            {
                if(n==4ll)
                {
                    sum=1ll*sum+3ll;
                    break;
                }
                if(n==1ll)
                {
                    sum=1ll*sum+1ll;
                    break;
                }
                if((n/2ll)%2ll==0)
                {
                    n=1ll*n-2ll;
                    sum=1ll*sum+1ll;
                }
                else
                {
                    n=1ll*n/2ll;

                    sum=1ll*sum+n;
                    n=1ll*n-1ll;
                }
            }

            printf("%lld\n",1ll*d-1ll*sum);
        }
    }
    return 0;
}