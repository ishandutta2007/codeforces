#include <iostream>
using namespace std;
int a[100005],b[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin >> b[i];
			cnt+=((b[i]-a[i])!=(b[i-1]-a[i-1]));
			if(a[i]>b[i]) cnt=3;
		}
		cnt+=b[n]!=a[n];
		if(cnt>2)
		{
			puts("NO");
		}
		else
		{
				puts("YES");
		}
	}
	return 0;
}