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

/*

namespace ModCalc{

	In void Inc(ll &x,ll y){x += y;if(x >= mod)x -= mod;}

	In void Dec(ll &x,ll y){x -= y;if(x < 0)x += mod;}

	In ll Add(ll x,ll y){Inc(x,y);return x;}

	In ll Sub(ll x,ll y){Dec(x,y);return x;}

};

using namespace ModCalc;

*/

const int N = 1e5;


template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}

template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}


int n;
ll dis[N+5],suf[N+5];

void solve(){
	n = read();
	rep(i,1,n)dis[i] = read();
	sort(dis,dis + n + 1);
	suf[n+1] = 0;
	ll ans = dis[n];
	dwn(i,n,1)suf[i] = suf[i+1] + dis[i];
//rep(i,1,n)cout<<suf[i]<<" ";cout<<endl;	
	dwn(i,n,1)ans -= (suf[i] - dis[i] * (n-i+1));
	write(ans),putchar('\n');
}


int main(){

//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();

	return 0;

}