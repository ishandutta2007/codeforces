#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int now=1;
	for(int i=1;i<=k;i++)
	{
		while(a[now]==a[now-1]&&now<=n) ++now;
		cout << max(0,a[now]-a[now-1]) << "\n";
		if(now<=n)++now;
	}
	return 0;
}