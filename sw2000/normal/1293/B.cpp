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
 
int main()
{
    // freopen("in.txt","r",stdin);
    int n;cin>>n;
    ld ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=(ld)1/i;
    }
    cout.setf(ios::fixed);
    cout.precision(12);
    cout<<ans;
    return 0;
}