#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
pair <int,int> a[10005];
int b[10005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	int mx=2;
	for(int i=3;i<=n;i++)
	{
		cout << "2 1 " << mx << " " << i << endl;
		int t;
		cin >> t;
		if(t==-1)
			mx=i;
	}
	for(int i=2;i<=n;i++)
	{
		if(i!=mx)
		{
			cout << "1 1 " << mx << " " << i << endl;
			cin >> a[i].first;
			a[i].second=i;
		}
	}
	sort(a+1,a+n+1);
	for(int i=3;i<n;i++)
	{
		cout << "2 1 " << a[i].second << " " << a[n].second << endl;
		int t;
		cin >> t;
		if(t==1) b[i]=1;
		else b[i]=0;
	}
	cout << "0 1 " << mx << " ";
	for(int i=3;i<n;i++)
		if(b[i])
			cout << a[i].second << " ";
	cout << a[n].second << " ";
	for(int i=n-1;i>2;i--)
		if(!b[i])
			cout << a[i].second << " ";
	cout << endl;
	return 0;
}