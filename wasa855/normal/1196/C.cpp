#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100000
void work()
{
	int mix=-N,maxx=N,miy=-N,may=N;
	int n=read();
	int x,y,a,b,c,d;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d %d %d",&x,&y,&a,&b,&c,&d);
		if(!a) mix=max(mix,x);
		if(!b) may=min(may,y);
		if(!c) maxx=min(maxx,x);
		if(!d) miy=max(miy,y);
	}
	if(mix>maxx||miy>may) cout<<"0\n";
	else printf("1 %d %d\n",mix,miy);
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}