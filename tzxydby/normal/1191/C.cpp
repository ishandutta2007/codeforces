#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long a[N]; 
int main()
{
	ios::sync_with_stdio(false);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	long long ans=0;
	for(int i=1;i<=m;)
	{
		ans++;
		long long q=a[i],del=i-1;
		while(i<=m&&(a[i]-1-del)/k==(q-1-del)/k)
			i++;
	}
	cout<<ans<<endl;
	return 0;
}