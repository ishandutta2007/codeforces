#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=min(a,b);
    int y=min(c,d);
    int m=max(a,b);
    int n=max(c,d);
    if(m==n&&x+y==m) cout<<"YES";
    else cout<<"NO"; 
    cout<<"\n";
    }   
}