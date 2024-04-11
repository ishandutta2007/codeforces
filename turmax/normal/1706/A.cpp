#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n,m;cin>>n>>m;string s;for(int i=0;i<m;++i) s.push_back('B');
    int a[n];for(int i=0;i<n;++i) {cin>>a[i];--a[i];a[i]=min(a[i],m-1-a[i]);if(s[a[i]]=='B') s[a[i]]='A'; else s[m-1-a[i]]='A';}
    cout<<s<<'\n';
    }
    return 0;
}