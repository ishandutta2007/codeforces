#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
#define ll long long
const int N=5000050;
char s[N],t[N*2];
int deg[N],f[N*2];
int main()
{
    int n,i;ll sol=0;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(i=1;i<n*2;i++)
    {
        if(i&1) t[i]=s[i/2+1];
        else t[i]='.';
    }
    int r=0,c=0;
    for(i=1;i<n*2;i++)
    {
        int k=1;
        if(r>=i) k=min(f[2*c-i],r-i+1);
        while(t[i+k]==t[i-k]) k++;
        if(i+k-1>r) r=i+k-1,c=i;
        f[i]=k;
    }
    for(i=1;i<=n;i++)
    {
        if(f[i]>=i) deg[i]=deg[i/2]+1;
        sol+=deg[i];
    }
    printf("%lld\n",sol);
    return 0;
}