#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        set<int> s;
        s.insert(0);
        for(int i=1;i*i<=n;i++) s.insert(n/i);
        for(int i=1;i*i<=n;i++) s.insert(i);
        cout<<s.size()<<'\n';
        for(int i:s) cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}