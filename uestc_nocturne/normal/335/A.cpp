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
const int V=1020;
char s[V];
int ct[120];
int n;
int main()
{
    while(~scanf("%s%d",s,&n))
    {
        memset(ct,0,sizeof(ct));
        int l=strlen(s);
        for(int i=0;i<l;i++)
        ct[s[i]-'a']++;
        int ret=-1;
        for(int i=1;i<=l;i++)
        {
            int use=0;
            for(int j=0;j<26;j++)
            {
                use+=ct[j]/i;
                if(ct[j]%i)use++;
            }
            if(use<=n)
            {
                ret=i;break;
            }
        }
        printf("%d\n",ret);
        if(ret!=-1)
        {
            int use=0;
            for(int j=0;j<26;j++)
            {
                int t=ct[j]/ret;
                if(ct[j]%ret)t++;
                use+=t;
                for(int k=0;k<t;k++)
                printf("%c",j+'a');
            }
            for(int j=use;j<n;j++)printf("z");
            puts("");
        }
    }
    return 0;
}