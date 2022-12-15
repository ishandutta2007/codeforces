#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n+1];
    a[0]=0;
    for(int i=1;i<n+1;i++)
    {
        cin>>a[i];
    }
    long long int totals[k+1]={0};
    int min=1;
    for(int i=1;i<(k+1);i++)
    {
        int j=0;
        while(i+j*k<=n)
        {
            totals[i]+=a[i+j*k];
            j++;
        }
        if(totals[i]<totals[min])
        {
            min=i;
        }
    }
    cout<<min;
    return 0;
}