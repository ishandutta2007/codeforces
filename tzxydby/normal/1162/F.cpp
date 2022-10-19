#include<bits/stdc++.h>
using namespace std;
const int N=2005,mod=998244353;
int a[N],b[N],pa[N],w[N],p[N],n,m,ans;
char s[N]; 
inline int getpa(int x)
{
	if(pa[x]==x)
		return x;
	int p=getpa(pa[x]);
	w[x]^=w[pa[x]];
	return pa[x]=p;
}
inline int link(int a,int b,int c)
{
	if(getpa(a)!=getpa(b))
	{
		w[pa[a]]=w[a]^w[b]^c;
		pa[pa[a]]=pa[b];
	}
	else if(w[a]^w[b]^c)
		return 0;
	return 1;
}
int solve(int A,int B)
{
	memset(pa,0,sizeof(pa));
	memset(w,0,sizeof(w));
	for(int i=1;i<=B*2+3;i++)
		pa[i]=i;
	m=0;
	int zero=++m;
	for(int i=0;i<=B;i++)
		a[i]=++m,(i>A?link(zero,m,0):0);
	for(int i=0;i<=B;i++)
		b[i]=++m;
	link(zero,a[0],1),link(zero,b[0],1);
	for(int i=0,j=A;i<j;i++,j--)
		if(!link(a[i],a[j],0))
			return 0;
	for(int i=0,j=B;i<j;i++,j--)
		if(!link(b[i],b[j],0))
			return 0;
	for(int i=0;i<=B;i++)
		if(s[i]!='?'&&!link(a[i],b[i],s[i]-'0'))
			return 0;
	int owo=0;
	for(int i=1;i<=m;i++)
		owo+=(pa[i]==i);
	return p[owo-1];
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	reverse(s,s+n);
	p[0]=1;
	for(int i=1;i<=n*2;i++)
		p[i]=p[i-1]*2%mod;
	for(int i=1;i<n;i++)
		ans=(ans+solve(i-1,n-1))%mod;
	printf("%d\n",ans);
	return 0;
}