#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        if(n%m==0) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}