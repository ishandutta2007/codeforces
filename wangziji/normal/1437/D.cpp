#include <iostream>
using namespace std;
int a[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int now=1,ans=0;
		for(int i=2;i<=n;i++)
		{
			int nxt=0,qwq=0;
			for(int j=i;j<=n;j++)
			{
				if(j==i||a[j]<a[j-1])
				{
					if(--now<0) break;
				}
					qwq=j;
					++nxt;
			}
			ans++;
			now=nxt,i=qwq;
		}
		cout << ans << "\n";
	}
	return 0;
}