#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    long long int a[n];
    long long int b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    long long int counter =0,j=m-1;
    for(int i=n-1;i>=0;i--)
    {
        if(j==-1)
        {
            counter++;
        }
        else
        {
        if(b[j]>=a[i])
        {
            j--;
        }
        else
        {
            counter++;
        }
        }
    }
    cout<<counter;
    return 0;
}