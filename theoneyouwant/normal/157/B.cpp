#include<iostream>
#include<algorithm>
using namespace std;

int main()

{
    int n;
    cin>>n;
    long double PI =   3.14159265358979323846;
    long double area =0;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    bool z=1;
    for(int i=n-1;i>=0;i--)
    {
        if(z==1)
        {
            area+=a[i]*a[i];
            z=0;
        }
        else
        {
            area-=a[i]*a[i];
            z=1;
        }
    }
    area = PI*area;
    cout<<area;
    return 0;
}