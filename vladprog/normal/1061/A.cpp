#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,s;
    cin>>n>>s;
    cout<<s/n+bool(s%n);
}