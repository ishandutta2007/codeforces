#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 100005
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	bool ok=true;
	if(a[n]>=a[n-1]+a[n-2])
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(int i=1;i<=n-3;i++) printf("%d ",a[i]);
	printf("%d %d %d\n",a[n-1],a[n],a[n-2]);
	return 0;
}

//sczfe