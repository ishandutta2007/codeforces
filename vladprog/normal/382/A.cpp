#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[26];
    memset(a,0,sizeof(a));
    int l=0,r=0,n=0;
    char c;
    while(true)
    {
        scanf("%c",&c);
        if(c=='|')
            break;
        else
            a[c-'A']=1,l++;
    }
    while(true)
    {
        scanf("%c",&c);
        if(c=='\n')
            break;
        else
            a[c-'A']=2,r++;
    }
    while(true)
    {
        if(scanf("%c",&c)==EOF||c=='\n')
            break;
        else
            a[c-'A']=3,n++;
    }
    int d=l+r+n;
    if(d%2)
        return printf("Impossible"),0;
    d/=2;
    int dl=d-l,dr=d-r;
    if(dl<0||dr<0)
        return printf("Impossible"),0;
    for(int i=0;i<26;i++)
        if(a[i]==3&&dl>0)
            a[i]=1,dl--;
    for(int i=0;i<26;i++)
        if(a[i]==1)
            printf("%c",(char)(i+'A'));
    printf("|");
    for(int i=0;i<26;i++)
        if(a[i]==2||a[i]==3)
            printf("%c",(char)(i+'A'));
}