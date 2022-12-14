#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        if(abs(x-y)==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}