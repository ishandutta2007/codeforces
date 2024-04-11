#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(2*min(a,b)<=max(a,b)) cout<<min(a,b)<<'\n';
        else cout<<(a+b)/3<<'\n';
    }
}