#include <iostream>
#include <algorithm>
using namespace std;
int a[100005],cnt[10005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		int t=a[i];
		for(int j=0;j<=30;j++)
			if(t&(1<<j))
				++cnt[j];
	}
	int ans=0,id=0;
	for(int i=1;i<=n;i++)
	{
		int t=0;
		for(int j=0;j<=30;j++)
		{
			if(a[i]&(1<<j))
				t+=(cnt[j]==1)*(1<<j);
		}
		if(t>=ans) ans=t,id=i;
	}
	swap(a[id],a[1]);
	for(int i=1;i<=n;i++)
		cout << a[i] << " ";
	return 0;
}