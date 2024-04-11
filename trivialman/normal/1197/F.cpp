#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 1005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const static int K = 70;
struct vec{
	int v[K],n;
	vec(int n=64){this->n=n; memset(v,0,sizeof v);}
	vec operator*(int b){
		vec res;
		rep(i,1,n)res.v[i] = 1ll*v[i]*b%P;
		return res;
	}
};
struct mat{
	int m[K][K], n;
	mat(int n=64){this->n = n; memset(m,0,sizeof m); }
	void setI(){rep(i,1,n)m[i][i]=1;}
	mat operator*(mat b){
		mat res;
		rep(i,1,n)rep(j,1,n)rep(k,1,n)
			res.m[i][j] = (res.m[i][j]+1ll*m[i][k]*b.m[k][j])%P;
		return res;
	}
	vec operator*(vec b){
		vec res;
		rep(i,1,n)rep(j,1,n)
			res.v[i] = (res.v[i] + 1ll * m[i][j] * b.v[j]) % P;
		return res;
	}
	mat operator*(int b){
		mat res;
		rep(i,1,n)rep(j,1,n)
			res.m[i][j] = 1ll*m[i][j]*b%P;
		return res;
	}
	mat operator+(mat b){
		mat res;
		rep(i,1,n)rep(j,1,n)
			res.m[i][j] = 1ll*(m[i][j]+b.m[i][j])%P;
		return res;
	}
};

int n, m, x, y, z, c, a[N], tot[N][5], dp[N][5];
vector<PII> b[N];
mat mt[4],trans[30];

vec pw(vec &x,int n){
	for(int i=0;n;++i,n>>=1)if(n&1)x=trans[i]*x;
}

void initMat(mat &m){
	int f[5],g[5];
	scanf("%d%d%d",f+1,f+2,f+3);
	rep(i,0,63){
		memset(g,0,sizeof g);
		int x=i>>4&3, y=i>>2&3, z=i&3, j=0;
		if(f[3])g[x]=1;
		if(f[2])g[y]=1;
		if(f[1])g[z]=1;
		for(;g[j];++j);
		int res = (y<<4) + (z<<2) + j;
		m.m[res+1][i+1]=1;
	}
}

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%d%d%d",&x,&y,&c);
		b[x].PB(MP(y,c)); 
	}
	rep(i,1,n)if(b[i].size()){
		sort(b[i].begin(), b[i].end());
	}
	
	rep(i,1,3)initMat(mt[i]);
	trans[0] = mt[1] + mt[2] + mt[3];
	rep(i,1,29) trans[i] = trans[i-1] * trans[i-1];
	
	memset(tot,0,sizeof tot);
	rep(i,1,n){
		vec tmp;tmp.v[61]=1;
		int sz = b[i].size();
		if(!sz){
			pw(tmp, a[i]-1);
			tmp = tmp * 3;
		}else{
			if(b[i][0].first>1){
				pw(tmp, b[i][0].first-2);
				tmp = mt[b[i][0].second] * tmp * 3;
			}
			rep(j,1,sz-1){
				pw(tmp, b[i][j].first - b[i][j-1].first - 1);
				tmp = mt[b[i][j].second] * tmp;
			}
			pw(tmp, a[i] - b[i][sz-1].first);
		}
		rep(j,0,63){
			tot[i][j&3] = (tot[i][j&3] + tmp.v[j+1]) % P;
		}
	}
	
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	rep(i,1,n)rep(j,0,3)rep(k,0,3){
		dp[i][j] = (dp[i][j] + 1ll * tot[i][k] * dp[i-1][j^k]) % P;
	}
	printf("%d\n",dp[n][0]);
	return 0;
}