#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int main()
{
    int n;
    cin>>n;
    if(n&1)
    {
        cout<<9+n<<' '<<9;
    }
    else cout<<4+n<<' '<<4;
    return 0;
}