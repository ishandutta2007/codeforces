#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int a[100005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,x;
		cin >> n >> x;
		for(int i=1;i<=n;i++) cin >> a[i];
		int s=0;
		for(int i=1;i<=n;i++) s+=a[i];
		if(s==x)
		{
			cout << "NO\n";
			continue;
		}
		s=0;
		for(int i=1;i<=n;i++)
		{
			s+=a[i];
			if(s==x)
			{
				swap(a[i],a[i+1]);
				break;
			}
		}
		puts("YES");
		for(int i=1;i<=n;i++)
			cout << a[i] << " ";
		cout << '\n';
	}
	return 0;
}