#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[1001],y[1001];
bool a[1001][1001];
int main()
{
    cin>>n>>m;
    while(getchar()!='\n');
    for(int i=1;i<=n;getchar(),i++)
        for(int j=1;j<=m;j++)
        {
        	char t=getchar();
            if(t=='*')  x[i]++,y[j]++,a[i][j]=1;
        }
    long long ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j])  ans+=(x[i]-1)*(y[j]-1);
    cout<<ans<<endl;
    return 0;
}