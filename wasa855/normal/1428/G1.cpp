#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 1000005
int a[N],b[N],f[N];
void push(int v,int w)
{
	for(int i=N-1;i>=w;i--) f[i]=max(f[i],f[i-w]+v);
}
void ins(int w,int v,int c)
{
	// printf("%d %d %d\n",w,v,c);
	for(int i=0;i<=20;i++)
	{
		if(c>=(1<<i))
		{
			c-=1<<i;
			push(v<<i,w<<i);
		}
		else
		{
			push(v*c,w*c);
			break;
		}
	}
}
signed main()
{
	int k=(read()-1)*3,pw=1;
	for(int i=1;i<N;i++) f[i]=-INF;
	for(int i=0;i<=5;i++)
	{
		int v=read();
		ins(3*pw,v,k);
		for(int j=N-1;j>=0;j--)
		{
			for(int k=0;k<=9;k++)
			{
				if(j>=k*pw)
				{
					if(k%3==0) f[j]=max(f[j],f[j-k*pw]+k/3*v);
					else f[j]=max(f[j],f[j-k*pw]);
				}
			}
		}
		pw*=10;
	}
	int Q=read();
	while(Q--) printf("%lld\n",f[read()]);
	return 0;
}