#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int maxn=3000;
int p,q,l,r,a,b,c[maxn+1],d[maxn+1];
bool ac[maxn+1]={},bc[maxn+1]={};
int main()
{
    cin>>p>>q>>l>>r;
    for(int i=1;i<=p;i++)
    {
        cin>>a>>b;
        for(int j=a;j<=b;j++) ac[j]=1;
    }
    for(int i=1;i<=q;i++) cin>>c[i]>>d[i];
    int suit=0;
    for(int k=l;k<=r;k++)
    {
        for(int i=0;i<=maxn;i++) bc[i]=0;
        for(int i=1;i<=q;i++)
            for(int j=c[i];j<=d[i];j++) bc[j+k]=1;
        bool ok=0;
        for(int i=0;i<=maxn;i++) if(ac[i]&&bc[i]) {ok=1; break;}
        suit+=ok;
    }
    cout<<suit;
    return 0;
}