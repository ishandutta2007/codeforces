#include<iostream>
using namespace std;

int main()
{
    int n;
    long long int t;
    cin>>n>>t;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int j=0;
    while(t>0)
    {
        t=t-(86400-a[j]);
        j=j+1;
    }
    cout<<j;
}