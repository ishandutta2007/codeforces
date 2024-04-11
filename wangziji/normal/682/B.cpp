#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int main(int argc, char** argv) {
	int now=1;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=10000000;i++)
	{
		while(now<=n&&a[now]<i) ++now;
		if(a[now]>=i)
		{
			++now;
			continue;
		}
		cout << i;
		return 0;
	}
	return 0;
}