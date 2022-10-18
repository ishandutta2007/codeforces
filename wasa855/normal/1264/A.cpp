#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 400005
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	a[n+1]=0;
	int g=0,s=0,b=0;
	for(int i=1;i<=n;i++)
	{
		g++;
		if(a[i]!=a[i+1]) break;
	}
	for(int i=g+1;i<=n;i++)
	{
		s++;
		if(a[i]!=a[i+1]&&s>g) break;
	}
	for(int i=g+s+1;i<=n;i++)
	{
		int j=i;
		while(a[j+1]==a[i]) j++;
		if(j>n/2) break;
		b+=j-i+1;
		i=j;
	}
	if(s>g&&b>g)
	{
		printf("%d %d %d\n",g,s,b);
	}
	else cout<<"0 0 0\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}