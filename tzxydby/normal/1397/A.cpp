#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int t,n,a[30];
char s[N];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<26;i++)
            a[i]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s+1);
            int m=strlen(s+1);
            for(int j=1;j<=m;j++)
                a[s[j]-'a']++;
        }
        int fl=1;
        for(int i=0;i<26;i++)
            if(a[i]%n)
                fl=0;
        puts(fl?"YES":"NO");
    }
    return 0;
}