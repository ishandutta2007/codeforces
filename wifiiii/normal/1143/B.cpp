#include<bits/stdc++.h>

using namespace std;

typedef int ll;

ll cal(ll n)
{
    ll ret= 1;
    while(n)
    {
        ret *= n%10;
        n /= 10;
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    int ans = cal(n);
    int b = 1;
    while(n>0)
    {
        while(n>0&&n%(10*b)!=10*b-1) n-=b;
        if(n<=0) break;
        ans = max(ans, cal(n));
        b*=10;
    }
    cout << ans << endl;
}