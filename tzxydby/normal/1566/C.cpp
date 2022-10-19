#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],b[N],f[N][5],c[5]={0,1,0,2};
char s[N],t[N];
inline void chmax(int &a,int b){if(a<b)a=b;}
void sol()
{
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'0',b[i]=t[i]-'0';
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<4;j++)
			f[i][j]=-1;
	f[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(f[i][j]==-1)
				continue;
			chmax(f[i+1][j|(1<<a[i])|(1<<b[i])],f[i][j]);
			chmax(f[i+1][0],f[i][j]+c[j|(1<<a[i])|(1<<b[i])]);
		}
	}
	printf("%d\n",f[n+1][0]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}