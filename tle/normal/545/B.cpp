#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
char s[1000001],t[1000001],h[1000001];
bool rp=0;
int main()
{
    scanf("%s%s",s,t);
    int n=strlen(t);
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i]) h[i]=s[i];
        else
        {
             if(rp) h[i]=s[i];
             else h[i]=t[i];
             rp=!rp;
        }
    }
    if(rp!=0) cout<<"impossible"; else printf("%s",h);
}