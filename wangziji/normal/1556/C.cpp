#include <bits/stdc++.h>
#define int long long
using namespace std;
int l[10005],r[10005],cnt;
inline void add(int x,int y)
{
	l[++cnt]=x,r[cnt]=y;
}
inline int ins(int l1,int r1,int l2,int r2)
{
	return max(0ll,min(r1,r2)-max(l1,l2)+1);
}
inline int query(int x,int y)
{
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		//cout << y << " " << x << " " << l[i] << " " << r[i] << " " <<ins(y,x,l[i],r[i])  << "\n";
		ans+=ins(y,x,l[i],r[i]);
	}
	return ans;
}
inline void cl(int x,int y)
{
	for(int i=1;i<=cnt;i++)
		if(r[i]>=y) r[i]=y-1;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,ans=0,now=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		if(i&1) add(now,now+x-1),now+=x;
		else ans+=query(now-1,now-x),cl(now,now-x+1),now-=x;
	}
	cout << ans;
	return 0;
}