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
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

ll two[100];
int solve()
{
    int n;scanf("%d",&n);
    for(int i=1;;i++)
        if(n%two[i]==0)return n/two[i];
}

int main()
{
//    freopen("in.txt","r",stdin);
    two[0]=1;
    for(int i=1;i<40;i++)
    {
        two[i]=two[i-1]+((ll)1<<i);
    }
    int _;cin>>_;
    while(_--)
    {
        printf("%d\n",solve());
    }
    return 0;
}