#include <bits/stdc++.h>

using namespace std;

int main()
{
    #define int long long
    int t,n,a,b;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>n>>a>>b;
        if(b<=(2*a))
        {
            if(n%2==0)
            {
                cout<<(n/2)*b<<endl;
            }
            else
            {
                cout<<(n/2)*b+a<<endl;
            }
        }
        else
        {
            cout<<(a*n)<<endl;
        }
    }
    return 0;
}