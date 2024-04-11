#include<stdio.h>
#include<vector>
#include<set>
#include<map>
using namespace std;
int M=2, phiM=0;
class mint
{
public:
	int x;
	mint(long long _x){ x=((_x%M)+M)%M; }
	mint &operator=(const long long A) { x = A%M; return *this; }
	mint operator+(const mint &A) const{ return 0ll+A.x+x; }
	mint operator+(const long long A)const{ return A+x; }
	mint operator+=(const mint &A){ x=(A+x).x; return *this; }
	mint operator-=(const mint &A){ return *this+=-A; }
	mint operator*(const mint &A) const{ return 1ll*A.x*x; }
	mint &operator*=(const mint &A) { x = 1ll*x*A.x%M; return *this; }
	mint pow(int p) const{
		mint re = 1, b = x;
		while(p)
		{
			if(p%2) re *= b;
			b = b*b; p/=2;
		}
		return re;
	}
	mint rev() const { return this->pow(phiM-1); }
	mint operator/(const mint &A) const{ return *this*A.rev(); }
	mint operator-() const { return -x; }
	mint operator-(const mint &A)const{ return *this + -A; }
	bool operator<(const mint &A)const{ return x<A.x; }
};
class moper
{
public:
	mint m, a;
	moper(mint M=1, mint A=0):m(M), a(A){}
	mint operator()(const mint &X)const{ return X*m+a; }
	moper operator+(const mint &A)const{ return moper(m, a+A); }
	moper operator-(const mint &A)const{ return moper(m, a-A); }
	moper operator*(const mint &A)const{ return moper(m*A, a*A); }
	moper rev(){ return (moper()-a)/m; }
	moper operator/(const mint &A)const{ return *this*A.rev(); }
	moper &operator+=(const mint A) { a += A; return *this; }
	moper &operator-=(const mint A) { a -= A; return *this; }
	moper &operator*=(const mint A) { a *= A; m *= A; return *this; }
	moper &operator/=(const mint A) { return (*this)*=(A.rev()); }
};

vector<pair<int, int>> in[100001];
map<mint, long long> Su[100001], Sd[100001];
moper ou[100001], od[100001];
long long ans = 0;

void getPhi()
{
	int x = M;
	phiM = M;
	for(int i=2; i*i<=x; i++)
	{
		if(x%i == 0)
		{
			while(x%i==0) x/=i;
			phiM = phiM/i*(i-1);
		}
	}
	if(x != 1) phiM = phiM/x*(x-1);
}

void dfs(int x, int p)
{
	Su[x][0]=1;
	Sd[x][0]=1;
	for(auto &xxp: in[x])
	{
		int xx = xxp.first, w = xxp.second;
		if(xx == p) continue;
		dfs(xx, x);

		(ou[xx]*=10)+=w;
		(od[xx]-=w)/=10;
		if(Su[xx].size() > Su[x].size())
		{
			Su[xx].swap(Su[x]);
			Sd[xx].swap(Sd[x]);
			swap(ou[xx], ou[x]);
			swap(od[xx], od[x]);
		}
		//
		for(auto &vp: Su[xx])
		{
			mint v = ou[xx](vp.first);
			ans += Sd[x][od[x].rev()(v)]*vp.second;
		}
		for(auto &vp: Sd[xx])
		{
			mint v = od[xx](vp.first);
			ans += Su[x][ou[x].rev()(v)]*vp.second;
			Sd[x][od[x].rev()(v)] += vp.second;
		}
		for(auto &vp:Su[xx])
		{
			mint v = ou[xx](vp.first);
			Su[x][ou[x].rev()(v)] += vp.second;
		}
	}
}
int main()
{
	int n;
	scanf("%d%d", &n, &M);
	getPhi();
	for(int i=1; i<n; i++)
	{
		int a, b, x;
		scanf("%d%d%d", &a, &b, &x);
		in[a].push_back(make_pair(b, x));
		in[b].push_back(make_pair(a, x));
	}
	dfs(0, -1);
	printf("%lld\n", ans);
	return 0;
}