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
const int V=1001000;
void e_kmp(char *s,char *t,int *has,int *e_has)  
{ 
     int sp,p,mx,tn; 
     for(sp=p=mx=0; s[p]>0; p++) 
     { 
         if( mx == p || p+e_has[p-sp]>=mx ) 
         { 
             for(tn = mx-p; s[mx]==t[tn]; tn++) 
                 mx++; 
             has[ sp=p ] = mx - p; 
             if( mx==p ) 
                 sp = mx = p+1; 
         } 
         else 
             has[ p ] = e_has[ p-sp ]; 
     } 
}
char s[V],t[V];
int has[V],e_has[V],i,le;
int main()
{
    while(~scanf("%s",s))
    {
        le=strlen(s);
        for(i=0;s[i];i++)
        t[i]=s[i];
        t[le] = -1; 
        e_has[0] = le; 
        e_kmp(t+1, t, e_has+1, e_has);  
        e_kmp(s, t, has, e_has);
        int ma=0;
        for(i=1;i<le;i++)
        {
            int te;
            if(i+has[i]==le)te=has[i]-1;
            else te=has[i];
            ma=max(ma,te);
        }
        int ret=-1;
        for(i=ma;i>0;i--)
        {
            if(has[le-i]==i)
            {ret=i;break;}
        }
        if(ret==-1)puts("Just a legend");
        else
        {
            for(i=0;i<ret;i++)
            printf("%c",s[i]);puts("");
        }
    }
}