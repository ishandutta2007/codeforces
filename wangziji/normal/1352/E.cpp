#include <iostream>
#include <cstring>
using namespace std;
int a[100005],vis[8005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		memset(vis,0,sizeof vis);
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
		{
			int s=a[i];
			for(int j=i+1;j<=n;j++)
			{
				s+=a[j];
				if(s>n) break;
				vis[s]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans+=vis[a[i]];
		cout<< ans << "\n";
	}
	return 0;
}