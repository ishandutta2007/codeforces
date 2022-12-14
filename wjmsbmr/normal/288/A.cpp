#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000010
int n,m;char s[N];
int main()
{
    scanf("%d%d",&n,&m);
    if(m==1)
    {
        if(n==1)puts("a");else puts("-1");
        return 0;
    }
    if(n<m){puts("-1");return 0;}
    for(int i=0;i<n;i++)s[i]='a'+(i&1);
    for(int i=m-1;i>=2;i--)
        s[n-1-(m-1-i)]='a'+i;
    puts(s);
    return 0;
}