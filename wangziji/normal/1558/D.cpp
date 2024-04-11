#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int jc[500005],jcinv[500005],inv[500005],x[200005],y[200005],p[200005],X[200005],pos[200005];
inline int C(int x,int y)
{
	return jc[x]*jcinv[y]%mod*jcinv[x-y]%mod;
}
int tree[500005];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void add(int x,int y)
{
	if(x>500000) return ;
	tree[x]+=y,add(x+lowbit(x),y);
}
inline int ask(int x)
{
	if(!x) return 0;
	return tree[x]+ask(x^lowbit(x));
}
inline int query(int k)
{
	int rtn=0;
	for(int i=(1<<17);i>=1;i>>=1)
		if(k>tree[rtn+i]) k-=tree[rtn+i],rtn+=i;
	return rtn+1;
}
signed main()
{
///	ios::sync_with_stdio(false);
//	cin.tie(0);
	jc[0]=jc[1]=jcinv[0]=inv[1]=jcinv[1]=1;
	for(int i=2;i<=500000;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		jcinv[i]=jcinv[i-1]*inv[i]%mod;
	}
	for(int i=1;i<=200000;i++) add(i,1);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		int k=0;
		for(int i=1;i<=m;i++)
			cin >> x[i] >> y[i];
	//	cin >> k;
		for(int i=m;i>=1;i--) p[x[i]]=query(y[i]),add(p[x[i]],-1);
		for(int i=1;i<=m;i++) add(p[x[i]],1),pos[p[x[i]]]=i;
	//	for(int i=1;i<=n;i++) cout << p[i] << " ";
	//	cout << "\n";
		k=n-1-m;
		int ans=0;
		for(int i=1;i<=m;i++) k+=(p[x[i]]<n)&&(pos[p[x[i]]]<pos[p[x[i]]+1]);
		cout << C(n+k,k) << "\n";
		for(int i=1;i<=m;i++) pos[p[x[i]]]=0,p[x[i]]=0;
	}
	return 0;
}