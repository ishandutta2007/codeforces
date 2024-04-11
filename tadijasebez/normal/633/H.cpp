#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define si short int
#define usi unsigned short int
const int N=30500;
const int M=2*N;
const int H=M*2;
int S=250;
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
si cnt[M];
si mod;
void ck(int &x){ while(x>=mod) x-=mod;}
int fib[2][2][2],inv[2][2],idm[2][2],tmp[2][2];
int sum[H][2][2],lzy[M][2][2];
usi ls[H],rs[H],tsz,root;
si zyl[H];
void Set(usi c, si ss, si se, si qi, int f)
{
	if(ss==se)
	{
		f%=mod;
		sum[c][0][0]=f*lzy[zyl[c]+N][0][0]%mod;
		sum[c][0][1]=f*lzy[zyl[c]+N][0][1]%mod;
		return;
	}
	si mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
	sum[c][0][0]=sum[ls[c]][0][0]+sum[rs[c]][0][0];ck(sum[c][0][0]);
	sum[c][0][1]=sum[ls[c]][0][1]+sum[rs[c]][0][1];ck(sum[c][0][1]);
	if(zyl[c]==0) return;
	int tmp=sum[c][0][0];
	sum[c][0][0]=(tmp*lzy[zyl[c]+N][0][0]+sum[c][0][1]*lzy[zyl[c]+N][1][0])%mod;
	sum[c][0][1]=(tmp*lzy[zyl[c]+N][0][1]+sum[c][0][1]*lzy[zyl[c]+N][1][1])%mod;
}
void Inc(usi c, si ss, si se, si qs, si qe, si f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se)
	{
		zyl[c]+=(f==0?1:-1);
		int t=sum[c][0][0];
		sum[c][0][0]=(t*fib[f][0][0]+sum[c][0][1]*fib[f][1][0])%mod;
		sum[c][0][1]=(t*fib[f][0][1]+sum[c][0][1]*fib[f][1][1])%mod;
		return;
	}
	si mid=ss+se>>1;
	Inc(c<<1,ss,mid,qs,qe,f);
	Inc(c<<1|1,mid+1,se,qs,qe,f);
	sum[c][0][0]=sum[ls[c]][0][0]+sum[rs[c]][0][0];ck(sum[c][0][0]);
	sum[c][0][1]=sum[ls[c]][0][1]+sum[rs[c]][0][1];ck(sum[c][0][1]);
	if(zyl[c]==0) return;
	int tmp=sum[c][0][0];
	sum[c][0][0]=(tmp*lzy[zyl[c]+N][0][0]+sum[c][0][1]*lzy[zyl[c]+N][1][0])%mod;
	sum[c][0][1]=(tmp*lzy[zyl[c]+N][0][1]+sum[c][0][1]*lzy[zyl[c]+N][1][1])%mod;
}
int a[N],l[N],r[N],idx[N],sol[N],sz;
bool comp(int i, int j){ return (l[i]/S==l[j]/S && ((r[i]<r[j]) ^ ((l[i]/S)&1))) || l[i]/S<l[j]/S;}
void Add(int i)
{
	int j=Find(a[i]);
	if(cnt[j]==0)
	{
		Set(root,1,sz,j,a[i]);
		Inc(root,1,sz,j,sz,0);
	}
	cnt[j]++;
}
void Del(int i)
{
	int j=Find(a[i]);
	cnt[j]--;
	if(cnt[j]==0)
	{
		Inc(root,1,sz,j,sz,1);
		Set(root,1,sz,j,0);
	}
}
int main()
{
	int n,q,i,j;
	scanf("%i %i",&n,&mod);
	fib[0][0][0]=1;
	fib[0][0][1]=1;
	fib[0][1][0]=1;
	fib[0][1][1]=0;
	fib[1][0][0]=0;
	fib[1][0][1]=1;
	fib[1][1][0]=1;
	fib[1][1][1]=mod-1;
	lzy[N][0][0]=lzy[N][1][1]=1;
	for(i=1;i<=n+5;i++)
	{
		lzy[i+N][0][0]=lzy[i+N-1][0][0]*fib[0][0][0]%mod+lzy[i+N-1][0][1]*fib[0][1][0]%mod;ck(lzy[i+N][0][0]);
		lzy[i+N][0][1]=lzy[i+N-1][0][0]*fib[0][0][1]%mod+lzy[i+N-1][0][1]*fib[0][1][1]%mod;ck(lzy[i+N][0][1]);
		lzy[i+N][1][0]=lzy[i+N-1][1][0]*fib[0][0][0]%mod+lzy[i+N-1][1][1]*fib[0][1][0]%mod;ck(lzy[i+N][1][0]);
		lzy[i+N][1][1]=lzy[i+N-1][1][0]*fib[0][0][1]%mod+lzy[i+N-1][1][1]*fib[0][1][1]%mod;ck(lzy[i+N][1][1]);
	}
	for(i=-1;i>=-n-5;i--)
	{
		lzy[i+N][0][0]=lzy[i+N+1][0][0]*fib[1][0][0]%mod+lzy[i+N+1][0][1]*fib[1][1][0]%mod;ck(lzy[i+N][0][0]);
		lzy[i+N][0][1]=lzy[i+N+1][0][0]*fib[1][0][1]%mod+lzy[i+N+1][0][1]*fib[1][1][1]%mod;ck(lzy[i+N][0][1]);
		lzy[i+N][1][0]=lzy[i+N+1][1][0]*fib[1][0][0]%mod+lzy[i+N+1][1][1]*fib[1][1][0]%mod;ck(lzy[i+N][1][0]);
		lzy[i+N][1][1]=lzy[i+N+1][1][0]*fib[1][0][1]%mod+lzy[i+N+1][1][1]*fib[1][1][1]%mod;ck(lzy[i+N][1][1]);
	}
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id.pb(a[i]);
	sort(id.begin(),id.end());id.erase(unique(id.begin(),id.end()),id.end());
	sz=id.size();
	root=1;
	for(i=1;i<=sz*2;i++) ls[i]=i<<1,rs[i]=i<<1|1;
	Inc(root,1,sz,1,sz,1);
	scanf("%i",&q);
	for(i=1;i<=q;i++) scanf("%i %i",&l[i],&r[i]),idx[i]=i;
	sort(idx+1,idx+1+q,comp);
	int L=1,R=0;
	for(j=1;j<=q;j++)
	{
		i=idx[j];
		while(R<r[i]) Add(++R);
		while(R>r[i]) Del(R--);
		while(L<l[i]) Del(L++);
		while(L>l[i]) Add(--L);
		sol[i]=sum[root][0][0];
	}
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	return 0;
}