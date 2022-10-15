#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
int ans=0;
    int k;
    cin>>k;
    while(k--)
    {
        string x;
    cin>>x;
    if(x[1]=='+')
        ans++;
    else
        ans--;
    }
    cout<<ans<<'\n';

    return 0;
}