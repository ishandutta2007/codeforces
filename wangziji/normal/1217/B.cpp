#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,x,mx=0,d=-100000000;
		cin >> n >> x;
		for(int i=1;i<=n;i++)
		{
			int a,b;
			cin >> a >> b;
			mx=max(a,mx);
			d=max(d,a-b);
		}
		x-=mx;
		if(x<=0)
		{
			puts("1");
		}
	else	if(d<=0)
	{
		puts("-1");
	}else cout << (x-1)/d+2 << "\n";
	}
	return 0;
}