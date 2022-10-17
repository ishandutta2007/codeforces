#include<iostream>
#include<string.h>
#include<algorithm>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll>LL;
LL a[100020]; 
int n,v;
ll f[100020];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i].X>>a[i].Y;
	cin>>v;
	for(int i=0;i<n;i++)
		a[i]=LL(a[i].X+a[i].Y*v,-a[i].X+a[i].Y*v);
	a[n++]=LL(0,0);
	sort(a,a+n);
	memset(f,0x3f,sizeof f);
	for(int i=n;i--;)
	{
		int p=upper_bound(f,f+n,-a[i].Y)-f;
		if(a[i]==LL(0,0))
			cout<<lower_bound(f,f+n,0)-f<<' ';
		else
			f[p]=-a[i].Y;
	}
	cout<<lower_bound(f,f+n,0x3f3f3f3f)-f;
	return 0;
}