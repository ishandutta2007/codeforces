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


const int N = 1e5;


template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}

template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}


ll n,a[N+5],b[N+5];

In ll calca(ll c){
	ll x = c - n,y = c - c / 4;
	if(y <= x)return y * 100;
	else return x * 100 + a[n-(y-x)+1];
}
In ll calcb(ll c){
	ll y = c - c / 4;
	if(y < n)return b[n-y+1];
	else return b[1];
}
void solve(){
	n = read();
	rep(i,1,n)a[i] = read();sort(a + 1,a + n + 1);dwn(i,n - 1,1)a[i] += a[i+1];
	rep(i,1,n)b[i] = read();sort(b + 1,b + n + 1);dwn(i,n - 1,1)b[i] += b[i+1];
	ll L = 0,R = n;
//cout<<calca(7)<<" "<<calcb(7)<<endl;
	while(L < R){
		int mid = (L + R) >> 1;
		if(calca(n+mid) >= calcb(n+mid))R = mid;
		else L = mid + 1;
	}
	write(L),putchar('\n');
}


int main(){

//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();	

	return 0;

}