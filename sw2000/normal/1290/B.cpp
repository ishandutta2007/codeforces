#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int n,arr[maxn],pre[150][maxn];
string s;

bool solve()
{
    int a,b;scanf("%d%d",&a,&b);
    a--;b--;
    if(a==b||s[a]!=s[b])return 1;
    int cnt=0;
    for(int i='a';i<='z';i++)if(pre[i][a]!=pre[i][b])cnt++;
    if(cnt<=2)return 0;
    else return 1;
}

int main()
{
    // freopen("in.txt","r",stdin);
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++)
    {
        if(i)for(int j='a';j<='z';j++)
        {
            pre[j][i]=pre[j][i-1];
        }
        pre[s[i]][i]++;
    }
    int q;cin>>q;
    while(q--)
    {
        if(solve())puts("Yes");
        else puts("No");
    }

    return 0;
}