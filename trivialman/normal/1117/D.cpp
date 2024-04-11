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
	void init(int k){
		rep(i,1,k-1)m[i][i+1]=1;
		m[k][1]=m[k][k]=1;
	}
	void setI(int k){
		rep(i,1,k)m[i][i]=1;
	}
	mat operator*(mat b){
		LL tmp[110][110];
		memset(tmp,0,sizeof tmp);
		rep(i,1,100)rep(j,1,100)rep(k,1,100){
			tmp[i][j]=(tmp[i][j]+m[i][k]*b.m[k][j])%MOD;
		}
		rep(i,1,100)rep(j,1,100)m[i][j]=tmp[i][j];
		return *this;
	}
};

LL n,k;

mat pw(mat x, LL n){
	mat res;res.setI(k);
	for(;n;n>>=1,x=x*x)if(n&1)res=res*x;
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	mat x;x.init(k);
	
	x = pw(x, n);
	LL ans = 0;
	rep(i,1,k)ans=(ans+x.m[1][i])%MOD;
	/*rep(i,1,k){
		rep(j,1,k)cout<<x.m[i][j]<<" ";
		cout<<endl;
	}*/
	cout<<ans<<endl;
	return 0;
}