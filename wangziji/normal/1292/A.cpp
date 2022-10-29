#include <iostream>
using namespace std;
int a[3][200005];
int main(int argc, char** argv) {
	int n,q,ans=0;
	cin >> n >> q;
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		if(!a[x][y])
		{
			a[x][y]=1;
			ans+=a[x^3][y]+a[x^3][y-1]+a[x^3][y+1];
		}
		else
		{
			a[x][y]=0;
			ans-=a[x^3][y]+a[x^3][y-1]+a[x^3][y+1];
		}
		if(ans)
			puts("No");
		else
			puts("Yes");
	}
	return 0;
}