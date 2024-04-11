#include <iostream>
using namespace std;
int a[100005];
signed main() {
	int n,q;
	cin >> n >> q;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		cnt+=!a[i];
	}
	while(q--)
	{
		int op,x;
		cin >> op >> x;
		if(op==1)
		{
			a[x]=1-a[x];
			if(a[x]==0) ++cnt;
			else --cnt;
		}
		else
		{
			if(n-cnt>=x)
			{
				puts("1");
			}
			else puts("0");
		}
	}
	return 0;
}