#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const ll A='A',C='C',G='G',T='T';

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;
    int ans=n*26;
    for(int i=0;i<n-3;i++)
        ans=min<ll>(ans,min(abs(s[i]-A),26-abs(s[i]-A))+
                        min(abs(s[i+1]-C),26-abs(s[i+1]-C))+
                        min(abs(s[i+2]-T),26-abs(s[i+2]-T))+
                        min(abs(s[i+3]-G),26-abs(s[i+3]-G)));
    cout<<ans;
}