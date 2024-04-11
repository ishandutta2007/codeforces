#include<iostream>

using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int a,b,ans;
        cin>>a>>b;
        if(a%2&&b%2==0)ans=(b-a+1)/2;
        else if(a%2&&b%2) ans=(b-a)/2-b;
        else if(a%2==0&&b%2) ans=-(b-a+1)/2;
        else if(a%2==0&&b%2==0) ans=-(b-a)/2+b;
        cout<<ans<<endl;
    }
}