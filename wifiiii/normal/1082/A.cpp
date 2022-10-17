#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y,d,t,ans=2e9+12;
        cin>>n>>x>>y>>d;
        if((y-x)%d==0) 
        {
            if(y>x) ans=min((y-x)/d+((y-x)%d!=0),ans);
            else ans=min((x-y)/d+((x-y)%d!=0),ans);
        }
        if((y-1)%d==0) ans=min(ans,(y-1)/d+((y-1)%d!=0)+(x-1)/d+((x-1)%d!=0));
        if((n-y)%d==0) ans=min(ans,(n-y)/d+((n-y)%d!=0)+(n-x)/d+((n-x)%d!=0));
        if(ans==2e9+12)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}