#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    int sit=0;
    for(int i=0;i<n;i++)
        if(s[i]=='x')
            sit++;
    sit-=n/2;
    printf("%d\n",abs(sit));
    if(sit>0)
        for(int i=0;i<n;i++)
        {
            if(sit!=0&&s[i]=='x')
            s[i]='X',sit--;
        }
    else if(sit<0)
        for(int i=0;i<n;i++)
        {
            if(sit!=0&&s[i]=='X')
            s[i]='x',sit++;
        }
    printf("%s\n",s);
}