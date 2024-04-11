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
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
const int maxn=100005;
int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if((s[i]-'0')%2==0)
            ans+=i+1;
    }
    cout<<ans<<endl;
    return 0;
}