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

/*	In char gc(){

		static char buf[100000],*p1 = buf,*p2 = buf;

		if(p1 == p2)p2 = buf + fread(p1 = buf,1,100000,stdin);

		return p1 == p2 ? EOF : *p1++;

	}*/

	In ll read(){

		ll s = 0,ww = 1;

		char ch = getchar();

		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}

		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}

		return s * ww;

	}

	In void write(ll x){

		if(x < 0)putchar('-'),x = -x;

		if(x > 9)write(x / 10);

		putchar('0' + x % 10);

	}

};

using namespace IO;

const ll mod = 998244353;
const int N = 1e5;



namespace ModCalc{

	In void Inc(ll &x,ll y){x += y;if(x >= mod)x -= mod;}

	In void Dec(ll &x,ll y){x -= y;if(x < 0)x += mod;}

	In ll Add(ll x,ll y){Inc(x,y);return x;}

	In ll Sub(ll x,ll y){Dec(x,y);return x;}

};

using namespace ModCalc;



template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}

template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}

In ll power(ll a,ll n){
	ll s = 1,x = a;
	while(n){
		if(n & 1)s = s * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return s;
}
ll jc[N+5],iv[N+5];
void prepro(){
	jc[0] = 1;rep(i,1,N)jc[i] = jc[i-1] * i % mod;
	iv[N] = power(jc[N],mod - 2);dwn(i,N - 1,0)iv[i] = iv[i+1] * (i + 1) % mod;
}

char s[N+5];
int a[N+5],n;

void solve(){
	n = read();scanf("%s",s + 1);
	rep(i,1,n)a[i] = s[i] - '0';
	int len = 0,x = 0,y = 0;
	rep(i,1,n)if(a[i] == 0)x++;
	rep(i,1,n){
		if(a[i] == 1)len++;
		else{
			y += len / 2;
			len = 0;
		}
	}	
	y += len / 2;
//cout<<"x="<<x<<" y="<<y<<endl;
	write(jc[x+y] * iv[x] % mod * iv[y] % mod),putchar('\n');
}


int main(){

//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	prepro();
	int Tc = read();
	while(Tc--)solve();

	return 0;

}