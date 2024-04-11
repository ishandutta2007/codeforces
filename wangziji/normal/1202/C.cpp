#include <iostream>
#define int long long
using namespace std;
inline int cal(string a)
{
	int x=0,y=0,mx=0,my=0,lx=0,ly=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='W') ++x;
		if(a[i]=='A') ++y;
		if(a[i]=='S') --x;
		if(a[i]=='D') --y;
		mx=max(mx,x),my=max(my,y);
		lx=min(lx,x),ly=min(ly,y);
	}
	return (mx-lx+1)*(my-ly+1);
}
signed main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		string a,b;
		cin >> a;
		b=a;
		int x=0,y=0,mx=0,my=0,lx=0,ly=0,wmx=0,wmy=0,wlx=0,wly=0;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='W') ++x;
			if(a[i]=='A') ++y;
			if(a[i]=='S') --x;
			if(a[i]=='D') --y;
			if(x>mx) wmx=i;
			if(x<lx) wlx=i;
			if(y>my) wmy=i;
			if(y<ly) wly=i;
			mx=max(mx,x),my=max(my,y);
			lx=min(lx,x),ly=min(ly,y);
		}
		int ans=(mx-lx+1)*(my-ly+1);
		a=a.substr(0,wmx)+'S'+a.substr(wmx,a.size()-wmx),ans=min(ans,cal(a)),a=b;
		a=a.substr(0,wlx)+'W'+a.substr(wlx,a.size()-wlx),ans=min(ans,cal(a)),a=b;
		a=a.substr(0,wmy)+'D'+a.substr(wmy,a.size()-wmy),ans=min(ans,cal(a)),a=b;
		a=a.substr(0,wly)+'A'+a.substr(wly,a.size()-wly),ans=min(ans,cal(a)),a=b;
		cout << ans << endl;
	}
	return 0;
}