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
int p[N],q[N];
int it[N];
int dif[N];
int ans[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read(),k=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) q[i]=read();
	for(int i=1;i<=n;i++) it[p[i]]=i;
	for(int i=1;i<=n;i++) q[i]=it[q[i]];
//	for(int i=1;i<=n;i++) printf("%d ",q[i]);
//	cout<<"\n";
	for(int i=1;i<n;i++)
	{
		if(q[i]>q[i+1]) dif[q[i+1]]++,dif[q[i]]--;
	}
	int tsum=0;
	for(int i=1;i<=n;i++)
	{
		if(tsum>0) ans[i]=ans[i-1];
		else ans[i]=ans[i-1]+1;
		tsum+=dif[i];
	}
	if(ans[n]<k) cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		for(int i=1;i<=n;i++)
		{
			printf("%c",min(ans[it[i]],k)-1+'a');
		}
		cout<<"\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}