#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll a,b,c;
    cin>>b;
    a=2;
    while(true)
    {
       if(a%2==0)
       {
           c=a/2;
           if((c*c)>=b)
           {
               cout<<a;
               return 0;
           }
       }
       if(a%2==1)
       {
           c=a/2;
           if((c*(c+1))>=b)
           {
               cout<<a;
               return 0;
           }
       }
       ++a;
    }
    return 0;
}