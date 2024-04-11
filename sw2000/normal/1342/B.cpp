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
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

string solve()
{
    string a;
    cin>>a;
    bool f[2]={0};
    for(auto i:a)f[i-'0']=1;
    if(f[0]==0||f[1]==0)
        return a;
    string ret;
    for(int i=0;i<a.size();i++)ret+="01";
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }

    return 0;
}