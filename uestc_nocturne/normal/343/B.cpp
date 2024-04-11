/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
int sn;
char s[V],t[V];
int main()
{
    while(~scanf("%s",s))
    {
        int n=strlen(s);
        sn=0;
        for(int i=0;i<n;i++)
        {
            if(sn>0&&t[sn-1]==s[i])
            sn--;
            else t[sn++]=s[i];
        }
        if(sn==0)puts("Yes");
        else puts("No");
    }
}