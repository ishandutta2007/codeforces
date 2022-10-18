#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 100005
int l[N];
vector<int> a[N];
int x[N],y[N];
int sum[N*10];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	int ans=0,m=0;
	for(int i=1;i<=n;i++)
	{
		l[i]=read();
		for(int j=1;j<=l[i];j++) a[i].push_back(read());
		bool ok=0;
		for(int j=0;j<l[i]-1;j++) if(a[i][j]<a[i][j+1]) ok=1;
		if(ok) ans++;
		else
		{
			m++;
			x[m]=a[i][0],y[m]=a[i][l[i]-1];
		}
	}
	ans=ans*m*2+ans*ans;
	for(int i=1;i<=m;i++) sum[x[i]]++;
	for(int i=1000000;i>=0;i--) sum[i]+=sum[i+1];
	for(int i=1;i<=m;i++)
	{
		ans+=sum[y[i]+1];
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}