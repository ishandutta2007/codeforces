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
const int oo=1000000000;
const int V=100100;
int Q,co[30][30],n;
char s[V],ch[120];
int main()
{
    while(~scanf("%s",s))
    {
        memset(co,0,sizeof(co));
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%s",ch);
            co[ch[0]-'a'][ch[1]-'a']=1;
            co[ch[1]-'a'][ch[0]-'a']=1;
        }
        n=strlen(s);
        int ans=0;
        int st=0;
        while(st<n)
        {
            int ed=st;
            int ct1=0,ct2=0;
            while(ed<n&&(s[ed]==s[st]||co[s[ed]-'a'][s[st]-'a']==1))
            {
                if(s[ed]==s[st])ct1++;
                else ct2++;
                ed++;
            }
            ans+=min(ct1,ct2);
            st=ed;
        }
        cout<<ans<<endl;
    }
}