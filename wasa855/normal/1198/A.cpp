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
#define N 400005
int a[N];
int b[N],cnt[N];
int n,I;
int pre[N*2];
int suf[N*2];
int sum[N*2];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>I;
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	int q=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+q+1,a[i])-b;
		cnt[a[i]]++;
	}
	int K=I*8/n;
	if(K>=20)
	{
		cout<<"0\n";return 0;
	}
	int len=1,ans=n;
	for(int i=1;i<=K;i++) len*=2;
	if(len>=q)
	{
		cout<<"0\n";return 0;
	}
	for(int i=1;i<=q;i++) pre[i]=pre[i-1]+cnt[i];
	for(int i=q;i>=1;i--) suf[i]=suf[i+1]+cnt[i];
	for(int i=1;i<=q-len+1;i++)
	{
		if(ans>suf[i+len]+pre[i-1]) ans=suf[i+len]+pre[i-1];
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}