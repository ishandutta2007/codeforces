#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,m;
char str[233333],dy[333];
int main()
{
    scanf("%d%d%s",&n,&m,str);
    for(int i=0;i<26;i++) dy[i]=i+'a';
    while(m--)
    {
        char xa[3],xb[3];
        scanf("%s%s",xa,xb);
        char a=xa[0],b=xb[0];
        for(int i=0;i<26;i++)
        {
            if(dy[i]==a) dy[i]=b; else if(dy[i]==b) dy[i]=a;
        }
    }
    for(int i=0;i<n;i++) putchar(dy[str[i]-'a']);
}