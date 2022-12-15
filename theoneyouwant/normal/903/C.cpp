#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long int max=0,current=a[0],sums=0;
    for(int i=0;i<n;i++)
    {
        if(current==a[i])
        {
            sums++;
        }
        else
        {
            if(sums>max)
            {
                max=sums;
            }
            current=a[i];
            sums=1;
        }
    }
    if(sums>max)
    {
        max=sums;
    }
    cout<<max;
    return 0;
}