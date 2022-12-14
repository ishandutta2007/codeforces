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
const int maxn = 2000 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int n,k,arr[maxn];
bitset<8>ten[10],s[maxn];
string ssss[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

bool dp[maxn][maxn*3];

void solve()
{
    if(dp[1][k]==0)
    {
        puts("-1");
        return;
    }
    vi ans;
    for(int i=1;i<=n;i++)
    {
        for(int j=9;;j--)if((s[i]&ten[j])==s[i])
        {
            int sub=ten[j].count()-s[i].count();
            if(dp[i+1][k-sub])
            {
                ans.push_back(j);
                k-=sub;
                break;
            }
            else if(j==0)
            {
                puts("-1");
                return;
            }
        }
    }
    for(auto i:ans)printf("%d",i);
}

int main()
{
    for(int i=0;i<10;i++)
    {
        bitset<8>t(ssss[i]);
        ten[i]=t;
    }
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    dp[n+1][0]=1;
    for(int i=n;i;i--)
    {
        for(int j=0;j<10;j++)if((s[i]&ten[j])==s[i])
        {
            int sub=ten[j].count()-s[i].count();
            for(int l=0;l<maxn;l++)if(dp[i+1][l])
                dp[i][l+sub]=1;
        }
    }
//    for(int i=1;i<=3;i++){
//        for(int j=0;j<10;j++)
//        cout<<dp[i][j];
//    cout<<endl;}
    solve();
    return 0;
}