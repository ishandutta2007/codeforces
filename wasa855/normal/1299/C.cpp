#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1000005
int a[N],n,sum[N];
int s[N],top;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=0;i<=n;i++)
	{
		while(top>=2)
		{
			int r1=(s[top]-s[top-1])*(sum[i]-sum[s[top]]);
			int r2=(i-s[top])*(sum[s[top]]-sum[s[top-1]]);
			if(r1>=r2) break;
			top--;
		}
		s[++top]=i;
	}
	for(int i=1;i<top;i++)
	{
		double D=(double)(sum[s[i+1]]-sum[s[i]])/(s[i+1]-s[i]);
		for(int j=s[i]+1;j<=s[i+1];j++) printf("%.10lf\n",D);
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}