#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n,a[1001],b[1001],mo=0;
int main()
{
    cin>>n;
    int cr=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        cr=cr+b[i]-a[i];
        mo=max(mo,cr);
    }
    cout<<mo;
}