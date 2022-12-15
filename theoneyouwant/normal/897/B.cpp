
 #include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long int k,j,l,mn;
    long long int p;
    cin>>k>>p;
    long long int a[k];
    a[0] = 11%p;
    for(long long int i=1;i<k;i++)
    {
        j=i+1;
        mn=i+1;
        l=0;
        while(j!=0)
        {
            mn=mn*10;
            l=l*10+j%10;
            j=j/10;
        }
        a[i]=(a[i-1]+mn+l)%p;
    }
    cout<<a[k-1];
    return 0;
}