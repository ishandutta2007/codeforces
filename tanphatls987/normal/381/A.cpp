#include <iostream>

using namespace std;

int main()
{
    int n,i,l,r,ansa,ansb,a[1000];
    cin>>n;
    for (i=0;i<n;i++) cin>>a[i];
    l=0;r=n-1;
    ansa=0;ansb=0;
    while (l<=r)
    {
        if (a[l]>a[r]) {ansa+=a[l];l++;} else {ansa+=a[r];r--;}
        if (l>r) break;
        if (a[l]>a[r]) {ansb+=a[l];l++;} else {ansb+=a[r];r--;}
    }
    cout<<ansa<<" "<<ansb;
}