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
const int maxn = 1000 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

char s[maxn];

int main()
{
    // freopen("in.txt","r",stdin);
    scanf("%s",s+1);
    int n=strlen(s+1);
    vi ans;
    for(int l=1,r=n;l<=r;)
    {
        if(s[l]==')')l++;
        else if(s[r]=='(')
        {
            r--;
        }
        else
        {
            ans.push_back(l);
            ans.push_back(r);
            l++;
            r--;
        }
    }
    if(ans.empty())puts("0");
    else
    {
        puts("1");
        printf("%d\n",ans.size());
        sort(ans.begin(),ans.end());
        for(auto i:ans)printf("%d ",i);
    }
    return 0;
}