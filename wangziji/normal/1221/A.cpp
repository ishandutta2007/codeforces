#include <iostream>
#include <cstring>
using namespace std;
int a[10005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++)
		{
			int t;
			cin >> t;
			if(t<4000)
			a[t]++;
		}
		for(int i=1;i<=1024;i++)
			a[i*2]+=a[i]/2;
		if(a[2048])
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}