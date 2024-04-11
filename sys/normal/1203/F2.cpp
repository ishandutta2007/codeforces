#include <bits/stdc++.h>
using namespace std;
const int t=6e4;
int n,r,f[t+5],ans,x,y;
struct w
{
	int x,y;
	bool operator < (const w &p) const
	{
		if((y>0)^(p.y>0)) return y>p.y;
		return y>0?x<p.x:x+y==p.x+p.y?x<p.x:x+y>p.x+p.y;
	}
}W[t];
int main()
{
	cin>>n>>r;
	memset(f,-0x3f,4*t+4);
	f[r]=0;
	for(int i=1;i<=n;i++)
		cin>>W[i].x>>W[i].y;
	sort(W+1,W+1+n);
	x=W[1].x,y=W[1].y;
	for(int i=1;i<=n;i++,x=W[i].x,y=W[i].y)
		if(y>0) for(int j=t-y;j>=x;j--) f[j+y]=max(f[j+y],f[j]+1);
		else for(int j=max(x,-y);j<=t;j++) f[j+y]=max(f[j+y],f[j]+1);
	for(int i=0;i<=t;i++) ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}