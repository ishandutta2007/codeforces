#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;    
int n,a[100001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    bool bok=0;
    for(int i=1;i<=n;i++)
    {
        bool ok=1;
        for(int j=1;j<=n;j++)
        {
            if(j%2==0) a[j]=(a[j]+1)%n;
            else a[j]=(a[j]-1+n)%n;
            if(a[j]!=j-1) ok=0;
        }
        if(ok)
        {
            bok=1; break;
        }
    }
    if(bok) cout<<"Yes"; else cout<<"No";
}