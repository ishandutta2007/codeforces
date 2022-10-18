#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 105
int a[N];
void work()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<n;i++)
	{
		m+=min(a[i]-a[i+1]+k,a[i]);
		if(m<0)
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//sdadw