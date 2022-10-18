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

    set<set<char>> s;
    int n;
    cin>>n;
    while(n--)
    {
        string t;
        cin>>t;
        s.insert(set<char>(t.begin(),t.end()));
    }
    cout<<s.size();
}