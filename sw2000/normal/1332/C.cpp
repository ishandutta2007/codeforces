#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

char s[maxn];

int solve()
{
    int ret=0;
    int n,k;scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=k/2;i++)
    {
       int cnt[26]={0};
       for(int j=i;j<=n;j+=k)cnt[s[j]-'a']++;
       for(int j=k+1-i;j<=n;j+=k)cnt[s[j]-'a']++;

       int ma=0;
       for(int j=0;j<26;j++)ma=max(ma,cnt[j]);
       ret+=n/k*2-ma;
    }
    if(k&1)
    {
        int cnt[26]={0};
        for(int j=k/2+1;j<=n;j+=k)cnt[s[j]-'a']++;
        int ma=0;
        for(int j=0;j<26;j++)ma=max(ma,cnt[j]);
        ret+=n/k-ma;
    }
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        printf("%d\n",solve());
    }
    return 0;
}