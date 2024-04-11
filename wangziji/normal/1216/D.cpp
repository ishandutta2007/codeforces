#include <iostream>
#define int long long
using namespace std;
inline int gcd(int x,int y)
{
	if(x<0) x=-x;
	if(y<0) y=-y;
	if(x>y)
		swap(x,y);
	while(x)
	{
		y%=x;
		swap(x,y);
	}
	return y;
}
int a[200005];
signed main() {
	int n,x=0;
	cin >> n;
	int mx=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++)
		x=gcd(x,mx-a[i]);
	int m=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			continue;
		m=max(m,((a[i]-1)/x+1));
		sum+=((a[i]-1)/x+1);
	}
	cout << (m*n-sum) << " " << x << endl;
	return 0;
}