#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[100005],x[100005],y[100005],cnt1,cnt2,qzh[100005];
signed main(int argc, char** argv) {
	int n,d,m;
	cin >> n >> d >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]<=m) x[++cnt1]=a[i];
		else y[++cnt2]=a[i];
	}
	sort(x+1,x+cnt1+1);
	int s=0;
	for(int i=1;i<=cnt1;i++)
		s+=x[i],qzh[i]=qzh[i-1]+x[i];
	sort(y+1,y+cnt2+1);
	int ans=s,pos=1,now=0;
	for(int i=1;i<=cnt2;i++)
	{
		now+=y[cnt2-i+1];
		int t=now;
		int X=(i-1)*d+i;
		if(X>n) break;
		X-=i,X-=(cnt2-i);
		X=max(X,(int)0);
	//	cout << i << " " << X << " " << now << " " << s << " " << qzh[X] << "\n";
		ans=max(ans,t+s-qzh[X]);
	}
	cout << ans;
	return 0;
}