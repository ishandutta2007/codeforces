#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int n,m;
    cin>>n>>m;
    if(!m)
    {
        cout << 1 << endl;
        return 0;
    }
    if(m==n)
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    if(n%2)
    {
        if(m<=n/2) ans = m;
        else if(m==n/2+1) ans = m-1;
        else ans = n-m;
    }
    else
    {
        if(m<=n/2) ans=m;
        else ans=n-m;
    }
    cout << ans << endl;
}