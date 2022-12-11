#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=mod?mod:0);
}
inline void sub(int &a,int b)
{
	a=a-b+(a<b?mod:0);
}
int R;
const int max_R=4e5+5;
int fac[max_R],inv[max_R],inv_fac[max_R];
inline void init()
{
	fac[0]=inv_fac[0]=1;
	fac[1]=inv[1]=inv_fac[1]=1;
	for(int i=2;i<=R;++i)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		inv_fac[i]=1ll*inv_fac[i-1]*inv[i]%mod;
	}
}
inline int C(int n,int m)
{
	if(n<0||m<0||n<m)
		return 0;
	return 1ll*fac[n]*inv_fac[m]%mod*inv_fac[n-m]%mod;
}
vector<int> pos[max_R];
const int max_n=2e5+5;
int a[max_n];
inline bool check(int x,int y)
{
	return x>=0&&y>=0&&y<a[x];
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;++i)
		scanf("%d",a+i);
	while(n>=0&&!a[n])
		--n;
	if(n==-1)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<=n;++i)
		pos[i+a[i]].push_back(i);
	for(int i=0;i+1<=n;++i)
		for(int j=a[i+1]+1;j<a[i];++j)
			pos[i+1+j].push_back(i+1);
	for(int i=0;i<a[n];++i)
		pos[n+1+i].push_back(n+1); 
	R=n+a[0];
	init();
	int ans=1,now=1;
	for(int i=1;i<=R;++i)
	{
		add(now,now);
		for(vector<int>::iterator it=pos[i].begin();it!=pos[i].end();++it)
		{
			int a=*it,b=i-a;
			if(check(a-1,b))
				sub(now,C(a-1+b,a-1));
			if(check(a,b-1))
				sub(now,C(a+b-1,a));
		}
//		fprintf(stderr,"i=%d now=%d\n",i,now);
		add(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}