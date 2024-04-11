#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const LL EULER = 402653184;

LL k,m,n,b[110];

struct mat{
	LL dat[110][110];
	mat(int x=0){memset(dat,0,sizeof dat);rep(i,1,k)dat[i][i]=x;}
	mat operator*(mat y){
		mat tmp;
		rep(i,1,k)rep(j,1,k)rep(l,1,k)
			tmp.dat[i][j]=(tmp.dat[i][j]+dat[i][l]*y.dat[l][j])%(MOD-1);
		return tmp;
	}
	mat operator%(LL x){return *this;}
}a;

template<class T>
T qpow(T a,LL n,LL MOD){
	T b=1;
	for(;n;n>>=1,a=a*a%MOD) if(n&1) b = b * a % MOD;
	return b;
}

LL GCD(LL x,LL y){
	LL r=0;
	while(x){r = y%x, y = x, x = r;}
	return y;
}

LL Indr(LL x){
	LL tmp=1;
	int M = (int)sqrt(MOD);
	map<LL, int> pws;
	rep(i,0,M)pws[tmp]=i,tmp=tmp*3%MOD;
	rep(i,0,MOD/M+1){
		tmp = qpow<LL>(3,MOD-1-i*M%(MOD-1),MOD) * x % MOD;
		if(pws[tmp])return pws[tmp]+i*M;
	}
}

int main(){
	cin>>k;
	rep(i,1,k)cin>>b[i];
	rep(i,1,k-1)a.dat[i][i+1]=1;
	rep(i,1,k)a.dat[k][i]=b[k+1-i];
	cin>>n>>m;
	a = qpow<mat>(a,n-k,MOD-1);
	LL npow = a.dat[k][k];
	LL gcd = GCD(npow, MOD-1);
	
	LL invL = qpow<LL>(npow/gcd, EULER-1, MOD-1);
	LL ind = Indr(m);
	if(ind % gcd != 0){
		cout<<-1<<endl;return 0;
	}
	ind /= gcd;
	cout<<qpow<LL>(3, ind * invL, MOD)<<endl; 
	return 0;
}