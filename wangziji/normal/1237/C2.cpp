#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int x,y,z,id;
}a[50005];
inline bool cmp(node x,node y)
{
	return x.x<y.x||x.x==y.x&&x.y<y.y||x.x==y.x&&x.y==y.y&&x.z<y.z;
}
int ans[50005],cnt;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		if(a[i].x>5e8) continue; 
		if(a[i].x==a[i+1].x&&a[i].y==a[i+1].y)
		{
			ans[++cnt]=a[i].id;
			ans[++cnt]=a[i+1].id;
			a[i].x=a[i+1].x=1e9;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		if(a[i].x>5e8) continue; 
		if(a[i+1].x==1e9) break;
		if(a[i].x==a[i+1].x)
		{
			ans[++cnt]=a[i].id;
			ans[++cnt]=a[i+1].id;
			a[i].x=a[i+1].x=1e9;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		if(a[i].x>5e8) continue; 
		if(a[i+1].x==1e9) break;
		ans[++cnt]=a[i].id;
		ans[++cnt]=a[i+1].id;
		a[i].x=a[i+1].x=1e9;
	}
	for(int i=1;i<=cnt;i+=2)
		cout << ans[i] << " " << ans[i+1] << "\n";
	return 0;
}