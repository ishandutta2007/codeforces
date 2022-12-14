#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;

bool solve()
{
    int x,n,m;
    scanf("%d%d%d",&x,&n,&m);
    for(int i=0;i<n;i++)
    {
        if(x/2+10<x)x=x/2+10;
        else break;
    }
    return x<=10*m;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("YES");
        else puts("NO");
    }
	return 0;
}