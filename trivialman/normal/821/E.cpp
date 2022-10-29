#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int INF = 0x3fffffff;
const int N = 1E6+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
struct mat{
	const static int K = 70;
	int m[K][K], n;
	mat(int n=K-1){this->n = n; memset(m,0,sizeof m); }
	void setI(){rep(i,1,n)m[i][i]=1;}
	mat operator*(mat b){
		mat res(n);
		rep(i,1,n)rep(j,1,n)rep(k,1,n)
			res.m[i][j] = (res.m[i][j]+1ll*m[i][k]*b.m[k][j])%P;
		return res;
	}
};
 
LL n, k, x, y, z, f[50], g[50];
 
mat pw(mat x, LL n){
	mat res(x.n); res.setI();
	for(;n;n>>=1,x=x*x)if(n&1)res=res*x;
	return res;
}
 
int main(){
	cin>>n>>k;
	int pz = 1;
	f[1] = 1;
	rep(i,1,n){
		cin>>x>>y>>z;
		y = min(y, k), ++z;
		mat a(z);
		rep(i,1,z)rep(j,i-1,i+1)if(j&&j<=z){
			a.m[i][j] = 1;
		}
		a = pw(a,y-x);
		
		swap(f, g);
		memset(f,0,sizeof f);
		rep(i,1,z)rep(j,1,z){
			(f[i] += a.m[i][j] * g[j]) %= P;
		}
		pz = z;
	}
	cout<<f[1]<<endl;
	return 0;
}