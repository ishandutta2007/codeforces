#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int k[26]={};
    while(n--)
    {
        string s;
        cin>>s;
        k[s[0]-'a']++;
    }
    #define cnt(x) ((x)*((x)-1)/2)
    int ans=0;
    for(int i=0;i<26;i++)
        ans+=cnt(k[i]/2)+cnt((k[i]+1)/2);
    cout<<ans;
}