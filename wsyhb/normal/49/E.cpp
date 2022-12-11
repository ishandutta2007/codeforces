#include<bits/stdc++.h>
using namespace std;
const int max_len=50+5;
char s1[max_len],s2[max_len];
int n;
const int max_n=50+5;
char a[max_n],b[max_n],c[max_n];
const int cnt_letters=26+5;
bool mark1[max_len][max_len][cnt_letters],mark2[max_len][max_len][cnt_letters];
int dp[max_len][max_len];
inline void init(char *s,bool mark[][max_len][cnt_letters],int len)
{
    for(int i=1;i<=len;++i)
        mark[i][i][s[i]-'a']=true;
    for(int l=1;l<=len;++l)
        for(int i=1;i+l-1<=len;++i)
        {
            int j=i+l-1;
            for(int p=1;p<=n;++p)
            {
                int x=a[p]-'a',y=b[p]-'a',z=c[p]-'a';
                for(int k=i;k<j;++k)
                    mark[i][j][z]|=mark[i][k][x]&mark[k+1][j][y];
            }
        }
}
int main()
{
    scanf("%s%s%d",s1+1,s2+1,&n);
    int l1=strlen(s1+1),l2=strlen(s2+1);
    for(int i=1;i<=n;++i)
    {
        do
        {
            scanf("%c",c+i);
        }while(c[i]<'a'||c[i]>'z');
        do
        {
            scanf("%c",a+i);
        }while(a[i]<'a'||a[i]>'z');
        do
        {
            scanf("%c",b+i);
        }while(b[i]<'a'||b[i]>'z');
    }
    init(s1,mark1,l1);
    init(s2,mark2,l2);
    for(int i=0;i<=l1;++i)
        for(int j=0;j<=l2;++j)
            dp[i][j]=1e9;
    dp[0][0]=0;
    for(int i=1;i<=l1;++i)
        for(int x=1;x<=i;++x)
            for(int p=0;p<26;++p)
            {
                if(mark1[x][i][p])
                {
                    for(int j=1;j<=l2;++j)
                        for(int y=1;y<=j;++y)
                        {
                            if(mark2[y][j][p])
                                dp[i][j]=min(dp[i][j],dp[x-1][y-1]+1);
                        }
                }
            }
    if(dp[l1][l2]==1e9)
        puts("-1");
    else
        printf("%d\n",dp[l1][l2]);
    return 0;
}