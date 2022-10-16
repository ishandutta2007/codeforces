#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,n;
        cin>>x>>y>>n;
        int a=(n/x)*x;
        a=a+y;
        if(a>n) a-=x;
        cout<<a<<'\n';

    }
}