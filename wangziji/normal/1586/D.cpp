#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans[105],b[105],n,tag[105];
inline int query()
{
	cout << "? ";
	for(int i=1;i<=n;i++) cout << b[i] << " ";
	cout << endl;
	int x;
	cin >> x;
	return x;
}
signed main(int argc, char** argv) {
	cin >> n;
	int pos=n,lst=n+1;
	while(pos>=1)
	{
		memset(tag,0,sizeof tag);
		for(int i=2;i<=n+1;i++)
		{
			int x=0;
			if(i<=n)
			{
				for(int j=1;j<=n;j++)
				{
					if(!ans[j]) b[j]=1;
					else b[j]=n;
				}
				b[pos]=i;
				x=query();
			}
			if(!x)
			{
				ans[pos]=lst-i+1,lst=ans[pos];
				for(int j=1;j<=n;j++)
					if(tag[j]) ans[j]=tag[j]+ans[pos]; 
				break;
			}
			tag[x]=i-1;
		}
		while(ans[pos]) --pos;
	}
	cout << "! ";
	for(int i=1;i<=n;i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}