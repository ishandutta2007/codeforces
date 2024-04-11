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

void solve()
{
    string s;cin>>s;
    bool vis[200]={0};
    char ans[100]={0};
    int st=50;
    for(auto i:s)
    {
        if(!ans[st])ans[st]=i;
        else
        {
            if(i==ans[st-1])
            {
                st--;
            }
            else if(i==ans[st+1])st++;
            else if(vis[i])
            {
                puts("NO");
                return;
            }
            else if(!ans[st-1])ans[--st]=i;
            else if(!ans[st+1])ans[++st]=i;
            else
            {
                puts("NO");
                return;
            }
        }
        vis[i]=1;
    }
    puts("YES");
    for(int i=0;i<100;i++)
    {
        if(ans[i])
        {
            printf("%c",ans[i]);
        }
    }
    for(int i='a';i<='z';i++)if(!vis[i])printf("%c",i);
    puts("");
}
 
int main()
{
    // freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)solve();
    return 0;
}