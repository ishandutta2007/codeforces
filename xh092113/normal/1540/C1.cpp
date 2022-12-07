#include<bits/stdc++.h>



using namespace std;



#define rg register

#define In inline

#define ll long long

#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)

#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)

#define mp make_pair

#define pb push_back

#define fi first

#define se second



namespace IO{

	In char gc(){

		static char buf[100000],*p1 = buf,*p2 = buf;

		if(p1 == p2)p2 = buf + fread(p1 = buf,1,100000,stdin);

		return p1 == p2 ? EOF : *p1++;

	}

	In ll read(){

		ll s = 0,ww = 1;

		char ch = gc();

		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = gc();}

		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = gc();}

		return s * ww;

	}

	In void write(ll x){

		if(x < 0)putchar('-'),x = -x;

		if(x > 9)write(x / 10);

		putchar('0' + x % 10);

	}

};

using namespace IO;


const int N = 100;
const int W = 1e5;
const ll mod = 1e9 + 7;


namespace ModCalc{

	In void Inc(ll &x,ll y){x += y;if(x >= mod)x -= mod;}

	In void Dec(ll &x,ll y){x -= y;if(x < 0)x += mod;}

	In ll Add(ll x,ll y){Inc(x,y);return x;}

	In ll Sub(ll x,ll y){Dec(x,y);return x;}

};

using namespace ModCalc;



template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}

template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}


int n;
int b[N+5],c[N+5],s[N+5],ss[N+5];
ll x,f[N+5][N*N+5];
ll sufp[N+5];

void solve(){
	ll ans = 0;
	sufp[n+1] = 1;
	dwn(i,n,1)sufp[i] = sufp[i+1] * (c[i]+1) % mod;
	rep(i,1,n - 1)s[i] = Add(s[i-1],b[i]);
	rep(i,1,n - 1)ss[i] = Add(ss[i-1],s[i]);
	f[0][0] = 1;
	rep(i,1,n){
		int limit = N * i;
		rep(j,0,limit){
			rep(d,0,c[i]){
				ll sum = j + d;
				if(i * x > sum - ss[i-1]){
					Inc(ans,f[i-1][j] * sufp[i+1] % mod);
				}
				else Inc(f[i][sum],f[i-1][j]);
			}
		}
	}
	ans = Sub(sufp[1],ans);
	write(ans),putchar('\n');
}


int main(){

//	freopen("C1.in","r",stdin);
//	freopen("C1.out","w",stdout);	

	n = read();
	rep(i,1,n)c[i] = read();
	rep(i,1,n - 1)b[i] = read();
	int qn = read();
	while(qn--){
		x = read();
		solve();
		memset(f,0,sizeof(f));
	}
	return 0;

}