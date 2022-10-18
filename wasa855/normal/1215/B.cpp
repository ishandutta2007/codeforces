#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(x>0) a[i]=1;
		else a[i]=-1;
	}
	int pos=0;
	for(int i=2;i<=n;i++)
	{
		a[i]*=a[i-1];
	}
	a[0]=1;
	int sp=0,sn=0;
	for(int i=0;i<=n;i++)
	{
		if(a[i]>0) pos+=sp,sp++;
		else pos+=sn,sn++;
	}
	printf("%lld %lld\n",n*(n+1)/2-pos,pos);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}