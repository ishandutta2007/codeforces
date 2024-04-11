#include <iostream>
#include <algorithm>
using namespace std;
int a[10005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int s=0;
		sort(a+1,a+n+1);
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			s+=a[i];
			if(s==0) flag=0;
		}
		if(flag)
		{
			puts("YES");
			for(int i=1;i<=n;i++)
				cout << a[i] << " ";
			puts("");
				continue;
		}
		reverse(a+1,a+n+1);
		s=0;
		flag=1;
		for(int i=1;i<=n;i++)
		{
			s+=a[i];
			if(s==0) flag=0;
		}
		if(flag)
		{
			puts("YES");
			for(int i=1;i<=n;i++)
				cout << a[i] << " ";
			puts("");
				continue;
		}
		puts("NO");
	}
	return 0;
}