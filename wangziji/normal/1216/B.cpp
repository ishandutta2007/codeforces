#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int id,x;
}a[100005];
inline bool cmp(node x,node y)
{
	return x.x>y.x;
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	long long ans=0,x=0;
	for(int i=1;i<=n;i++)
		ans+=a[i].x*x+1,++x;
	cout << ans << endl;
	for(int i=1;i<=n;i++)
		cout << a[i].id << " ";
	return 0;
}