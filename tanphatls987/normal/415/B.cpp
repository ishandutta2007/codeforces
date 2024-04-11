#include <iostream>
using namespace std;

int main()
{
    int64_t n,a,uc,b,ans,i,tmp;
    cin>>n>>a>>b;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        ans=((tmp*a)%b)/a;
        cout<<ans<<" ";
    }
}