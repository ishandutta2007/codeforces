#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
int a[100001];
int main()
{
    int n,now=0,t=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        t+=max(a[i]-a[i-1]-now,0);
        a[i-1]+=max(a[i]-a[i-1]-now,0);
        now+=a[i-1]-a[i];
    }
    cout<<t;
}