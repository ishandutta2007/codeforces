
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)
#define debug(i) cout<<#i<<":"<<i<<endl;

int main()
{
    int n,a,x,b,y;
    cin>>n>>a>>x>>b>>y;
    while(1)
    {
        if(a==b)
        {
            cout<<"yes"<<endl;
            return 0;
        }
        if(a==x) break;
        if(b==y) break;
        ++a,--b;
        if(a==n+1) a=1;
        if(b==0) b=n;
    }
    cout<<"no"<<endl;
}