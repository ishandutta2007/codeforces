#include <iostream>
using namespace std;
long long n,k,a[100001],m[100001],i,j,x;
main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (x=1;true;x++){
        if (x*(x+1)/2>=k)
        break;
    }
    k-=x*(x-1)/2;
    cout<<a[k]<<endl;
}