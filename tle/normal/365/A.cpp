#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    int n,k,st=0;
    char s[100001];
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&s);
        int tmp=strlen(s);
        if(tmp<=k) continue;
        bool r[10001]={},t=true;
        for(int i=0;i<tmp;i++) {r[s[i]-'0']=true;}
        for(int i=0;i<=k;i++) t=t&&r[i];
        if(t) st++;
    }
    printf("%d",st);
}