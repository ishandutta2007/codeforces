#include <iostream>
#include <cstdio>
using namespace std;
int a[200005],b[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),b[i]=0;
		cin >> m;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			b[y]=max(b[y],x);
		}
		for(int i=n-1;i>=1;i--)
			b[i]=max(b[i],b[i+1]);
		int now=1,flag=0,ans=0;
		while(now<=n&&!flag)
		{
			++ans;
			int mx=0;
			if(a[now]>b[1])
			{
				puts("-1");
				flag=1;
				break;
			}
			int t=0;
			for(int j=now;j<=n+1;j++)
			{
				now=j;
				if(j==n+1)
				{
					flag=2;
					break;
				}
				mx=max(mx,a[j]);
				if(b[++t]<mx)
					break;
				//cout << t << ' ' << b[t] << ' ' << a[j] << ' ' << j << endl; 
			}
			//cout << now << endl;
		}
		if(flag!=1)
			printf("%d\n",ans);
	}
	return 0;
}