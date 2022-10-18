#include<bits/stdc++.h>

using namespace std;

int n,k,a[100];

bool ok(int p)
{
    return (p>=0)&&(p<n)&&(a[p]<=k)&&(a[p]>0);
}

int main()
{
    int m;
    cin>>n>>m>>k;
    m--;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;;i++)
        if(ok(m-i)||ok(m+i))
            return cout<<i*10 , 0;
}