#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    else if(b==0)
    {
        return a;
    }
    else if(b>a)
    {
        return gcd(a,b-a);
    }
    else
    {
        return gcd(b,a-b);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int t;
    for(int i=0;i<n;++i)
    {
        cin>>t;
        cout<<max(180/gcd(t,180),(540-t-1)/(180-t))<<endl;
    }
    return 0;
}