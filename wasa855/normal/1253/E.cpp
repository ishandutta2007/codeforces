#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 100005
int x[N],s[N],f[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) x[i]=read(),s[i]=read();
	for(int i=1;i<=m;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		bool ok=0;
		for(int j=1;j<=n;j++) if(x[j]-s[j]<=i&&i<=x[j]+s[j]) ok=1;
		if(ok) f[i]=f[i-1];
		for(int j=1;j<=n;j++)
		{
			if(x[j]+s[j]<i) if(f[max(0,2*x[j]-i-1)]+i-x[j]-s[j]<f[i]) f[i]=f[max(0,2*x[j]-i-1)]+i-(x[j]+s[j]);
		}
	}
	cout<<f[m]<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}