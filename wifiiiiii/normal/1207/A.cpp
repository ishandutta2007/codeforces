#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int b,p,f,h,c;
int check(int x,int y)
{
    if(2*x+2*y<=b && x<=p && y<=f) return x*h+y*c;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        cin>>b>>p>>f;
        cin>>h>>c;
        int ans=0;
        for(int i=0;i<=100;++i)
            for(int j=0;j<=100;++j)
                ans=max(ans,check(i,j));
        cout<<ans<<endl;
    }
}