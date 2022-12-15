#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    int n;
    long long int l;
    cin>>n>>l;
    long long int a[n];
    long long int maxy;
    long double d;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    d=a[0];
    for(int i=0;i<n-1;i++)
    {
        if((a[i+1]-a[i])*1.0/2>d)
        {
            d = 1.0*(a[i+1]-a[i])/2;
        }
    }
    if(l-a[n-1]>d)
    {
        d=l-a[n-1];
    }
    maxy = 2*d;
    printf("%.10f\n",maxy/2.0);
    return 0;
}