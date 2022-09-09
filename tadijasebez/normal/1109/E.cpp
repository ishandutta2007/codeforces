#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

int mod;
int add(int a, int b){ a+=b;return a>=mod?a-mod:a;}
void ckadd(int &a, int b){ a=add(a,b);}
int sub(int a, int b){ a-=b;return a<0?a+mod:a;}
void cksub(int &a, int b){ a=sub(a,b);}
int mul(int a, int b){ return (ll)a*b%mod;}
void ckmul(int &a, int b){ a=mul(a,b);}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,ckmul(x,x)) if(k&1) ckmul(ans,x);return ans;}
int inv(int x){ return powmod(x,mod-2);}

const int N=100050;
int F[N],I[N];
int binom(int n, int k){ return mul(F[n],mul(I[k],I[n-k]));}
void calc()
{
	F[0]=1;
	for(int i=1;i<N;i++) F[i]=mul(F[i-1],i);
	I[N-1]=inv(F[N-1]);
	for(int i=N-2;~i;i--) I[i]=mul(I[i+1],i+1);
}

vector<int> p;
int Euler(int x)
{
	int ans=x;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ans/=i;
			ans*=(i-1);
			while(x%i==0) x/=i;
			p.pb(i);
		}
	}
	if(x>1) ans/=x,ans*=x-1,p.pb(x);
	return ans;
}

const int M=2*N;
const int L=20;
struct STAdd
{
	int sum[M];
	void init(){ for(int i=0;i<M;i++) sum[i]=0;}
	STAdd(){ init();}
	void Add(int l, int r, int f)
	{
		for(l+=N,r+=N;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) sum[l]+=f,l++;
			if(r%2==0) sum[r]+=f,r--;
		}
	}
	int Get(int i){ int ans=0;for(i+=N;i;i>>=1) ans+=sum[i];return ans;}
} FAC[L];

struct STMul
{
	int ls[M],rs[M],tsz,root,sum[M],lzy[M];
	void init(){ root=tsz=0;}
	STMul(){ init();}
	void Build(int &c, int ss, int se, int a[])
	{
		c=++tsz;lzy[c]=1;
		if(ss==se){ sum[c]=a[ss];return;}
		int mid=ss+se>>1;
		Build(ls[c],ss,mid,a);
		Build(rs[c],mid+1,se,a);
		sum[c]=add(sum[ls[c]],sum[rs[c]]);
	}
	void Push(int c)
	{
		if(lzy[c]==1) return;
		lzy[ls[c]]=mul(lzy[ls[c]],lzy[c]);
		sum[ls[c]]=mul(sum[ls[c]],lzy[c]);
		lzy[rs[c]]=mul(lzy[rs[c]],lzy[c]);
		sum[rs[c]]=mul(sum[rs[c]],lzy[c]);
		lzy[c]=1;
	}
	void Mul(int c, int ss, int se, int qs, int qe, int f)
	{
		if(qs>qe || qs>se || ss>qe) return;
		if(qs<=ss && qe>=se)
		{
			sum[c]=mul(sum[c],f);
			lzy[c]=mul(lzy[c],f);
			return;
		}
		int mid=ss+se>>1;
		Push(c);
		Mul(ls[c],ss,mid,qs,qe,f);
		Mul(rs[c],mid+1,se,qs,qe,f);
		sum[c]=add(sum[ls[c]],sum[rs[c]]);
	}
	int Get(int c, int ss, int se, int qs, int qe)
	{
		if(qs>qe || qs>se || ss>qe) return 0;
		if(qs<=ss && qe>=se) return sum[c];
		int mid=ss+se>>1;
		Push(c);
		return add(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
	}
	void Set(int c, int ss, int se, int qi, int f)
	{
		if(ss==se){ sum[c]=f;return;}
		Push(c);
		int mid=ss+se>>1;
		if(qi<=mid) Set(ls[c],ss,mid,qi,f);
		else Set(rs[c],mid+1,se,qi,f);
		sum[c]=add(sum[ls[c]],sum[rs[c]]);
	}
} Bez,Sa;
int a[N],b[N];
int main()
{
	//calc();
	int n,q,i,j;
    scanf("%i %i",&n,&mod);
    int euler=Euler(mod);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		b[i]=a[i];
		for(j=0;j<p.size();j++)
		{
			int cnt=0;
			while(b[i]%p[j]==0) cnt++,b[i]/=p[j];
			FAC[j].Add(i,i,cnt);
		}
		a[i]%=mod;
		b[i]%=mod;
	}
	Bez.Build(Bez.root,1,n,b);
	Sa.Build(Sa.root,1,n,a);
    scanf("%i",&q);
    int l,r,x,t,id;
    while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i %i",&l,&r,&x);
			int y=x;
			for(j=0;j<p.size();j++)
			{
				int cnt=0;
				while(y%p[j]==0) cnt++,y/=p[j];
				FAC[j].Add(l,r,cnt);
			}
			x%=mod;
			y%=mod;
			Bez.Mul(Bez.root,1,n,l,r,y);
			Sa.Mul(Sa.root,1,n,l,r,x);
		}
		else if(t==2)
		{
			scanf("%i %i",&id,&x);
			int y=x;
			int my=1;
			for(j=0;j<p.size();j++)
			{
				int cnt=0;
				while(y%p[j]==0) cnt++,y/=p[j];
				FAC[j].Add(id,id,-cnt);
				my=mul(my,powmod(p[j],FAC[j].Get(id)));
			}
			int bz=Bez.Get(Bez.root,1,n,id,id);
			int bez=mul(bz,powmod(y,euler-1));
			Bez.Set(Bez.root,1,n,id,bez);
			int sa=mul(bez,my);
			Sa.Set(Sa.root,1,n,id,sa);
		}
		else
		{
			scanf("%i %i",&l,&r);
			printf("%i\n",Sa.Get(Sa.root,1,n,l,r));
		}
	}
	return 0;
}