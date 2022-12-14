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

int solve()
{
    string s;cin>>s;
    bool flag=0;
    int ret=0,cnt=0;
    for(auto i:s)
    {
        if(i=='1')
        {
            if(flag)ret+=cnt;
            flag=1;
            cnt=0;
        }
        else cnt++;
    }
    return ret;
}

int main()
{
    // freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}