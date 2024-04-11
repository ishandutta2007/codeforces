#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q,a,b,c;
    cin>>q;
    for(int i=0;i<q;++i)
    {
    cin>>a>>b>>c;
    cout<<(a+b+c)/2<<endl;
    }
    return 0;
}