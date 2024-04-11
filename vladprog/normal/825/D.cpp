#include<bits/stdc++.h>

using namespace std;

int main()
{
    char cs[1000001],ct[1000001];
    scanf("%s%s",cs,ct);
    string s=cs,t=ct;
    int ns=s.length(),nt=t.length(),ks[26],kt[26],v=0;
    memset(ks,0,sizeof(ks));
    memset(kt,0,sizeof(kt));
    for(int i=0;i<ns;i++)
        if(s[i]!='?')
            ks[s[i]-'a']++;
        else
            v++;
    for(int i=0;i<nt;i++)
        kt[t[i]-'a']++;
    for(int i=0;true;i++)
    {
        int tv=v;
        for(int j=0;j<26;j++)
            tv-=max(0,i*kt[j]-ks[j]);
        if(tv<0)
        {
            i--;
            //printf("%d\n",i);
            int k=0;
            for(int j=0;j<26;j++)
            {
                int p=max(0,i*kt[j]-ks[j]);
                while(p>0)
                {
                    while(s[k]!='?')
                        k++;
                    s[k]=j+'a';
                    p--;
                }
            }
            for(int i=0;i<ns;i++)
                if(s[i]=='?')
                    s[i]='a';
            printf("%s",s.c_str());
            exit(0);
        }
    }
}