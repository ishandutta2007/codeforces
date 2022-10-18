#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 55
int a[N][N];
int x[N*N],y[N*N];
int ans;
signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=read();
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
            {
                x[++ans]=i,y[ans]=j;
            }
        }
    }
    for(int i=1;i<=ans;i++)
    {
        a[x[i]][y[i]]=0;
        a[x[i]+1][y[i]]=0;
        a[x[i]][y[i]+1]=0;
        a[x[i]+1][y[i]+1]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j])
            {
                cout<<"-1\n";
                return 0;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++)
    {
        printf("%d %d\n",x[i],y[i]);
    }
    return 0;
}