#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
int a[maxn],vis[maxn];
int main()
{
	int n;
	cin>>n;
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int mid=n/2+n%2;
	for(int i=1;i<=mid;i++)
		if(a[i]-i>=0){
			vis[a[i]-i]++;
		}
	for (int i=n;i>mid;i--)
		if(a[i]-(n-i+1)>=0) {
			vis[a[i]-(n-i+1)]++;
		}
	int mx=0;
	for(int i=0;i<maxn;i++)
		mx=max(mx, vis[i]);
	cout<<n-mx<<endl;
	return 0;
}