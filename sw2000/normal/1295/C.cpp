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
int pre[maxn][150];

int solve()
{
    string s,t;
    cin>>s>>t;
    for(int i=0;i<150;i++)
    {
        pre[s.size()][i]=-1;
    }
    for(int i=s.size()-1;~i;i--)
    {
        for(int j='a';j<='z';j++)
        {
            pre[i][j]=pre[i+1][j];
        }
        pre[i][s[i]]=i;
    }

    int ret=1,st=0;
    for(auto i:t)
    {
        if(pre[0][i]==-1)return -1;
        if(pre[st][i]==-1)
        {
            ret++;
            st=pre[0][i]+1;
        }
        else
        {
            st=pre[st][i]+1;
        }
    }
    return ret;
}

int main()
{
    // freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        printf("%d\n",solve());
    }
    return 0;
}