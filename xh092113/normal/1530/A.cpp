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



template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}

template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}


void solve(){
	int n = read();
	int ans = 0;
	while(n){chkmax(ans,n%10);n /= 10;}
	write(ans),putchar('\n');
}


int main(){

//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();	

	return 0;

}