#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,lst=0,mx,mn;
		cin >> n >> m;
		mx=mn=m;
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin >> x >> y >> z;
			mx=min(mx+(x-lst),z);
			mn=max(mn-(x-lst),y);
			if(mx<y||mn>z) flag=0;
			lst=x;
		}
		if(!flag) puts("NO");
		else puts("YES");
	}
	return 0;
}