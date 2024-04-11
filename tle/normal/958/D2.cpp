#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(int x = (l);x<=(u);x++)
#define RREP(x,l,u) for(int x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 200010;
const int mod1 = 1e9+7,mod2 = 1e9+9;
const int MAX = 1000000010;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

struct Number{
	int n1,n2;
	Number(int n1=0,int n2=0):n1((n1%mod1+mod1)%mod1),n2((n2%mod2+mod2)%mod2) {}
};

Number operator+(Number a,int x){return Number(a.n1+x,a.n2+x);}
Number operator+(Number a,Number b){return Number(a.n1+b.n1,a.n2+b.n2);}

Number operator-(Number a,int x){return Number(a.n1-x,a.n2-x);}
Number operator-(Number a,Number b){return Number(a.n1-b.n1,a.n2-b.n2);}

Number operator*(Number a,int x){return Number((ll)a.n1*x%mod1,(ll)a.n2*x%mod2);}
Number operator*(Number a,Number b){return Number((ll)a.n1*b.n1%mod1,(ll)a.n2*b.n2%mod2);}

bool operator<(Number a,Number b){return (a.n1!=b.n1)?(a.n1<b.n1):(a.n2<b.n2);}

Number inv(Number a){
	return Number(fexp(a.n1,mod1-2,mod1),fexp(a.n2,mod2-2,mod2));
}

struct Matrix{
	Number a[6][6];
	void clear(){REP(i,1,5)REP(j,1,5)a[i][j]=Number(0,0);}
	void print(){
		REP(i,1,5){
			REP(j,1,5)printf("%d %d             ",a[i][j].n1,a[i][j].n2);
			puts("");
		}
	}
};

bool operator<(Matrix a,Matrix b){
	REP(i,1,5)REP(j,1,5)if(a.a[i][j]<b.a[i][j]||b.a[i][j]<a.a[i][j])return a.a[i][j]<b.a[i][j];
	return false;
}

Matrix uni(Matrix A){
	int nowi=1,nowj=1;
	while(nowi<=5&&nowj<=5){
		int t=nowi;
		REP(j,nowi+1,5)if(A.a[j][nowj].n1!=0&&A.a[j][nowj].n2!=0)t=j;
		REP(j,1,5)swap(A.a[nowi][j],A.a[t][j]);
		if(!A.a[nowi][nowj].n1||!A.a[nowi][nowj].n2){nowj++;continue;}
		REP(j,1,5)if(j!=nowi){
			Number t=inv(A.a[nowi][nowj]);
			RREP(k,5,nowj)A.a[j][k]=A.a[j][k]-A.a[j][nowj]*t*A.a[nowi][k];
		}
		Number tmp=inv(A.a[nowi][nowj]);
		REP(j,1,5)A.a[nowi][j]=A.a[nowi][j]*tmp;
		nowi++;nowj++;
	}
/*	REP(i,1,5){
		int t=i;
		REP(j,i+1,5)if(A.a[j][i].n1!=0&&A.a[j][i].n2!=0)t=j;
		REP(j,1,5)swap(A.a[i][j],A.a[t][j]);
		if(!A.a[i][i].n1||!A.a[i][i].n2)continue;
		REP(j,1,5)if(j!=i){
			Number t=inv(A.a[i][i]);
			REP(k,i,5)A.a[j][k]=(A.a[j][k]-A.a[j][i]*t*A.a[i][k]);
		}
	}*/
/*	REP(i,1,5)if(A.a[i][i].n1&&A.a[i][i].n2){
		Number t=inv(A.a[i][i]);
		REP(j,1,5)A.a[i][j]=A.a[i][j]*t;
	}*/
	return A;
}

int n,d,tot;

Matrix A;

int Ans[maxn];

map<Matrix,int> mp;

void Work(){
	REP(i,1,n){
		A.clear();
		int k;read(k);
		REP(j,1,k)REP(x,1,d){
			int t;read(t);
			A.a[j][x]=Number(t,t);
		}
		A=uni(A);
//		A.print();
		if(!mp[A])mp[A]=++tot;
		Ans[i]=mp[A];
	}
	REP(i,1,n)printf("%d ",Ans[i]);
}

void Init(){
	read(n,d);
}

int main(){
	Init();
	Work();
	return 0;
}
//123131313