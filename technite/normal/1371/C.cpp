#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,n,m;
        cin>>a>>b>>n>>m;
        if(n+m>a+b) {cout<<"NO"<<'\n';continue;}
        else if(min(a,b)==0&&m!=0)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        else
        {
            if(m>min(a,b))
            {
                cout<<"NO"<<'\n';
                continue;
            }
            else 
            {
                cout<<"YES"<<'\n';
                continue;
            }
        }
    }
}