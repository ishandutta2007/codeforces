#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    while(n--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(a<b)swap(a,b);
        ll gc=__gcd(a,b);
        a/=gc;
        b/=gc;
        ll ma=(a-2)/b+1;
        if(ma>=c)cout<<"REBEL"<<endl;
        else cout<<"OBEY"<<endl;
    }
    return 0;
}