#include<iostream>
using namespace std;

int main()
{
    long long int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int z=0;
    for(long long int i=0;i<n;i++)
    {
        z=z+a[i];
    }
    if(z+n-1 == x)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}