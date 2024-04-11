#include <iostream>
#define int long long
using namespace std;
int a[500005],ANS[500005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int ans=0,w=0;
	for(int i=1;i<=n;i++)
	{
		int now=a[i],t=0;
		for(int j=i;j>0;j--)
		{
			now=min(now,a[j]);
			t+=now;
		}
		now=2e9;
		for(int j=i+1;j<=n;j++)
		{
			now=min(now,a[j]);
			t+=now;
		}
		if(t>ans)
		{
			ans=t;
			w=i;
		}
	}
	int now=2e9;
	for(int j=w;j>0;j--)
	{
		now=min(now,a[j]);
		ANS[j]=now;
	}
	now=2e9;
	for(int i=w+1;i<=n;i++)
	{
		now=min(now,a[i]);
		ANS[i]=now;
	}
	for(int i=1;i<=n;i++)
		cout << ANS[i] << " ";
	return 0;
}