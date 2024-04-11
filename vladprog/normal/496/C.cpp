#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char a[n][m+1];
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    bool b[n-1];
    memset(b,0,sizeof(b));
    int ans=0;
    for(int i=0;i<m;i++)
    {
        bool d=false;
        for(int j=0;j<n-1;j++)
            d|=!b[j]&&a[j][i]>a[j+1][i];
        if(d)
            ans++;//,printf("%d ",i);
        else
            for(int j=0;j<n-1;j++)
                b[j]|=a[j][i]<a[j+1][i];
    }
    printf("%d",ans);
}