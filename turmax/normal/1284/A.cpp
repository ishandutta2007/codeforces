#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <string> a(n);
    vector <string> b(m);
    string s;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    int q;
    cin>>q;
    int x;
    for(int i=0;i<q;++i)
    {
        cin>>x;
        x--;
        cout<<(a[x%n]+b[x%m])<<endl;
    }
    return 0;
}