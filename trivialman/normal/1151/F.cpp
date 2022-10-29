#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 100010;

struct mat{
	LL m[110][110];
	mat(){memset(m,0,sizeof m);}
	mat operator*(mat b){
		mat c;
		rep(i,1,101)rep(j,1,101)rep(k,1,101){
			c.m[i][j]=(c.m[i][j]+m[i][k]*b.m[k][j])%MOD;
		}
		return c;
	}
};

LL n,k,n0=0,n1=0,l0=0,l1=0,a[110];

LL pw(LL x, LL n){
	LL res=1;
	for(;n;n>>=1,x=x*x%MOD)if(n&1)res=res*x%MOD;
	return res;
}
mat pw(mat x, LL n){
	mat res;
	rep(i,1,101)res.m[i][i]=1;
	for(;n;n>>=1,x=x*x)if(n&1)res=res*x;
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)if(a[i]==0) ++n0; else ++n1;
	LL tot=n*(n-1)/2%MOD, invtot=pw(tot,MOD-2);
	mat trans;
	rep(i,1,n0+1){
		int l0=i-1,l1=n0-l0,r0=l1,r1=n1-r0;
		trans.m[i][i-1]=l0*max(r1,0)*invtot%MOD;
		trans.m[i][i+1]=l1*r0*invtot%MOD;
		trans.m[i][i]=(1-trans.m[i][i-1]-trans.m[i][i+1]+MOD*2)%MOD;
	}
	trans = pw(trans,k);
	rep(i,1,n0)if(a[i]==0) ++l0;
	cout<<trans.m[l0+1][n0+1]<<endl;
	return 0;
}