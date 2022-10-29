#include <iostream>
using namespace std;
int a[100005],hzh[100005],tag[100005];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cnt+=(i+j<=n);
	for(int i=1;i<=n;i++) a[i]=i;
	if(cnt<m)
	{
		puts("-1");
		return 0;
	}
	cnt-=m;
	int now=n,x=(n-1)/2;
	for(int i=1;i<=cnt;i++)
	{
		while(!x) tag[now]=1,--now,x=(now-1)/2;
		hzh[now]+=2,--x;
	}
	for(int i=1;i<=n;i++) hzh[i]+=hzh[i-1];
	for(int i=1;i<=n;i++)
	{
		if(tag[i]) cout << 1000000000-20000*(n-i) << " ";
		else cout << a[i]+hzh[i] << " ";
	}
	return 0;
}