#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1005][10];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    int res=6;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            int cnt=0;
            for(int k=0;k<6;k++)
                if(s[i][k]!=s[j][k])cnt++;
            res=min(res,(cnt-1)/2);
        }
    printf("%d\n",res);
    return 0;
}