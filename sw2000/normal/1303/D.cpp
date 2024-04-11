#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

map<int,int>two;
int solve()
{
    ll n,m;scanf("%lld%lld",&n,&m);
    ll sum=0;
    int cnt[65]={0},arr[65]={0};
    for(int i=0;i<m;i++)
    {
        int a;scanf("%d",&a);
        sum+=a;
        cnt[two[a]]++;
    }
    if(sum<n)return -1;
    for(int i=0;i<62;i++)
    {
        if(n&1)arr[i]=1;
        n>>=1;
    }
    // for(int i=0;i<=5;i++)cout<<arr[i];cout<<endl;

    int ret=0;
    for(int i=0;i<62;i++)
    {
        if(arr[i])
        {
            int j=i;
            while(!cnt[j])
            {
                cnt[j]=1;
                ret++;
                j++;
            }
            if(j!=i)cnt[j]--;
            cnt[i]--;
        }

        cnt[i+1]+=cnt[i]/2;
    }
    return ret;
}

int main()
{
    // freopen("in.txt","r",stdin);
    for(int i=0;i<31;i++)two[1<<i]=i;
    int _;cin>>_;
    while(_--)printf("%d\n",solve());
    return 0;
}