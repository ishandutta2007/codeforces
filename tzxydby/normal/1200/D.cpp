    #include<bits/stdc++.h>
    using namespace std;
    const int N=2010;
    int n,k,ans,tot,r[N][N],c[N][N],okr[N][N],okc[N][N];
    char mp[N][N];
    int main()
    {
        scanf("%d%d%*c",&n,&k);
        for(int i=1;i<=n;scanf("%*c"),i++)
            for(int j=1;j<=n;j++)
                scanf("%c",&mp[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                r[i][j]=r[i][j-1]+(mp[i][j]=='B'),c[i][j]=c[i][j-1]+(mp[j][i]=='B');
        for(int i=1;i<=n;i++)tot+=(r[i][n]==0)+(c[i][n]==0);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n-k+1;j++)
                okr[i][j]=(r[i][j+k-1]-r[i][j-1]==r[i][n]&&r[i][n]!=0)+okr[i-1][j],
                okc[i][j]=(c[i][j+k-1]-c[i][j-1]==c[i][n]&&c[i][n]!=0)+okc[i-1][j];
        for(int i=1;i<=n-k+1;i++)
            for(int j=1;j<=n-k+1;j++)
                ans=max(ans,tot+okr[i+k-1][j]-okr[i-1][j]+okc[j+k-1][i]-okc[j-1][i]);
        printf("%d",ans);
    }