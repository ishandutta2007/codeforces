#include <bits/stdc++.h>

using namespace std;
#define int long long
int po(int x)
{
    if(x==0)
    {
        return 1;
    }
    if(x==1)
    {
        return 10;
    }
    if(x%2==0)
    {
        int u=po(x/2);
        return u*u;
    }
    else
    {
        int u=po(x-1);
        return u*10;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int x=0;
    int y=0;
    int a=1;
    while(x<n)
    {
        y=x;
        x+=a*(9*po(a-1));
        ++a;
    }
    a--;
    x=y;
    n-=x;
    n--;
    //cout<<n<<endl;
    int z=(n/a);
    int t=(n%a);
    int u=z+po(a-1);
    int h=a-t;
    //cout<<a<<" "<<h<<" "<<u<<endl;
    cout<<(u%po(h))/po(h-1);
    return 0;
}