#include <iostream>
using namespace std; 
int s[110000]; 
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        s[i]=s[i-1]+a;
    }
    int ans=0;
    for(int i=1; i<=n-1; i++)
    {
        if(s[i]==s[n]-s[i])
        {
            ans++; 
        }
    }
    cout<<ans; 
    return 0; 
}