#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
    int n,t=0,q=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++)
    {
        while(q<n&&a[q]<=a[i])
            q++;
        if(q<n)
            t++;
        q++;
            }
    cout<<t<<endl;
    return 0;
}