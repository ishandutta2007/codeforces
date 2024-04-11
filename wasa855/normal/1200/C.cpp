#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m,q;
	cin>>n>>m>>q;
	int gcd=__gcd(n,m);
	for(int i=1;i<=q;i++)
	{
		int sx,sy,ex,ey;
		sx=read(),sy=read(),ex=read(),ey=read();
		sy--,ey--;
		int xx,yy;
		if(sx==1) xx=sy/(n/gcd);
		else xx=sy/(m/gcd);
		if(ex==1) yy=ey/(n/gcd);
		else yy=ey/(m/gcd);
		if(xx==yy) cout<<"YES\n";
		else cout<<"NO\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//sacws