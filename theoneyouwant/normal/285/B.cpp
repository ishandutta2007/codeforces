#include<iostream>

using namespace std;
int main()
{
    int d,n,s,t;
    cin>>n>>s>>t;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int counter1=0;
    while(s!=t)
    {
        d=a[s-1];
        s=d;
        counter1+=1;
        if(counter1>n)
        {
            cout<<"-1";
            break;
        }
    }
    if(counter1<=n)
    {
        cout<<counter1;
    }
    return 0;
}