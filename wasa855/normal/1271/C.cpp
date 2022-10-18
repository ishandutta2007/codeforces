#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int x[N],y[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,sx,sy;
	cin>>n>>sx>>sy;
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	int l=0,r=0,u=0,d=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]>sx) u++;
		if(x[i]<sx) d++;
		if(y[i]>sy) r++;
		if(y[i]<sy) l++;
	}
	int ans=max(u,max(d,max(l,r)));
	cout<<ans<<endl;
	if(u==ans) printf("%d %d\n",sx+1,sy);
	else if(d==ans) printf("%d %d\n",sx-1,sy);
	else if(r==ans) printf("%d %d\n",sx,sy+1);
	else if(l==ans) printf("%d %d\n",sx,sy-1);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

//