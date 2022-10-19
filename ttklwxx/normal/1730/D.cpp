#include<iostream>
#include<cstdio>
using namespace std;
int sl[27][27];
char s[200005],t[200005];
int main()
{
    int sjzs;
    scanf("%d",&sjzs);
    int n;
    for(int greg=1;greg<=sjzs;greg++)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        for(int i=1;i<=26;i++)for(int j=1;j<=26;j++)sl[i][j]=0;
        for(int i=1;i<=n;i++)
        {
            sl[s[i]-'a'+1][t[n+1-i]-'a'+1]++;
            if(s[i]-'a'+1!=t[n+1-i]-'a'+1)sl[t[n+1-i]-'a'+1][s[i]-'a'+1]++;
        }
        bool flag=true;
        int sy=1;
        for(int i=1;i<=26;i++)
        {
            for(int j=1;j<=26;j++)
            {
                if(sl[i][j]%2==0)continue;
                if(i!=j)
                {
                    flag=false;
                    break;
                }
                if(i==j)
                {
                    sy--;
                    if(sy<0)
                    {
                        flag=false;
                        break;
                    }
                }
            }
        }
        if(flag==true)printf("YES\n");
        else printf("NO\n");
    }
}