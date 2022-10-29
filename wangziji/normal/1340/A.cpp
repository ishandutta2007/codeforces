#include <iostream>
using namespace std;
int a[100005],pos[100005],vis[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			pos[a[i]]=i;
			vis[i]=0;
		}
		vis[n+1]=1;
		int now=0,flag=1;
		for(int i=1;i<=n;i++)
		{
			if(now==0)
			{
				now=pos[i],vis[now]=1;
				continue;
			}
			++now;
			if(vis[now])
			{
				now=0,i--;
				continue;
			}
			if(now!=pos[i])
				flag=0;
			else vis[now]=1;
		}
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}