#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<sstream>
typedef long long LL;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const LL MMod=998244353;
#define maxn 50010
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
LL PowMod(LL a, LL b, const LL &Mod) {
    a %= Mod;
    LL ans = 1;
    while(b) {
        if (b & 1){
            ans = (ans * a) % Mod;
        }
        a = (a * a) % Mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int w,h;
    cin>>w>>h;
    cout<<PowMod(2,w+h,MMod);
    return 0;
}