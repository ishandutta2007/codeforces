#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
char s1[100010],s2[100010];
int n,tot1,tot2;
int main()
{
    scanf("%s%s",s1+1,s2+1);
    n=strlen(s1+1);
    for(int i=1;i<=n;i++)
        if(s1[i]!=s2[i])
        {
            if(s1[i]=='4') tot1++;
            else tot2++;
        }
    printf("%d\n",min(tot1,tot2)+tot1-min(tot1,tot2)+tot2-min(tot1,tot2));
    return 0;
}