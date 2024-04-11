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
        ll a,b;
        cin>>a>>b;
        if(a<b)swap(a,b);
        b=b*2-a;
        if(b>=0&&b%3==0)
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}