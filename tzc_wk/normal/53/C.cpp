#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int pos=1,l=0,r=n+1;
    for(int i=1;i<=n;i++)
    {
        cout<<pos<<" ";
        if(pos==l+1)  l++,pos=r-1;
        else  r--,pos=l+1;
    }
    return 0;
}