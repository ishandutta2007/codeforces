#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    long long int t=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)
        {
            t=t+a[i]+1;
        }
        else
        {
            if(a[i]>a[i-1])
            {
                t=t+2+a[i]-a[i-1];
            }
            else
            {
                t=t+2+a[i-1]-a[i];
            }
        }
        
    }
    cout<<t;
}