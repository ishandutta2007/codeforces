#include <iostream>
using namespace std;
int ans[200005],a[200005],vis[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			vis[i]=ans[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				int cnt=0;
				for(int j=i;;j=a[j])
				{
					++cnt;
					if(vis[j])
					{
						ans[i]=cnt;
						break;
					}
					vis[j]=i;
				}
			}
		}
		for(int i=1;i<=n;i++)
			cout << ans[vis[i]]-1 << " ";
		cout << endl;
	}
	return 0;
}