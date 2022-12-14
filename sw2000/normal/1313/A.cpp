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
const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int solve()
{
    int a[3],ret=0;
    for(int i=0;i<3;i++)
    {
        scanf("%d",a+i);
        if(a[i])a[i]--,ret++;
    }
    sort(a,a+3);
    if(a[0]>=3)ret+=4;
    else if(a[0]==2)ret+=3;
    else if(a[0]==1&&a[2]>=2)ret+=2;
    else if(a[1]>=1)ret+=1;
    return ret;
}

int main()
{
    // freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)printf("%d\n",solve());
    return 0;
}