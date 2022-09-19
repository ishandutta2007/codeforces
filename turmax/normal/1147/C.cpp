#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    set <int> d;
    int a[n];
    multiset <int> h;
    for(int i=0;i<n;++i) {cin>>a[i];d.insert(a[i]);h.insert(a[i]);}
    if(h.count(*d.begin())>(n/2))
    cout<<"Bob";
    else
    cout<<"Alice";
    return 0;
}