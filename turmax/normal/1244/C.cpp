#include <bits/stdc++.h>

using namespace std;
#define int long long
int gcd(int x,int y)
{
    if(x==0)
    {
        return y;
    }
    if(y==0)
    {
        return x;
    }
    if(x>=y)
    {
        return gcd(x%y,y);
    }
    else
    {
        return gcd(y%x,x);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,p,d,w;
    cin>>n>>p>>w>>d;
    int x=p;
    int u1=0,u2=0;
    if((x%(gcd(d,w)))!=0)
    {
        cout<<(-1);
        return 0;
    }
    while(true)
    {
        if(x%w==0)
        {
            u1=x/w;
            break;
        }
        else
        {
            x-=d;
            u2++;
        }
    }
    if((u1+u2)>n || u1<0)
    {
        cout<<(-1);
        return 0;
    }
    else
    {
        cout<<u1<<" "<<u2<<" "<<(n-u1-u2)<<endl;
    }
    return 0;
}