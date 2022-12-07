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



const int N = 2e5;


template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}

template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}


int n,a[N+5],b[N+5];
bool fu[N+5],fd[N+5];
int s1[N+5],top1;
int s2[N+5],top2;

void solve(){
	n = read();
	rep(i,1,n)a[i] = read();
	rep(i,1,n)fu[i] = fd[i] = 0;
	int ans = 0;
	rep(i,1,n){
		if(!fd[a[i]]){
			b[i] = a[i];
			fu[i] = 1;
			fd[a[i]] = 1;
			ans++;
		}
	}
	cout<<ans<<endl;
	top1 = 0;rep(i,1,n)if(fu[i] && !fd[i])s1[++top1] = i;
	top2 = 0;rep(i,1,n)if(!fu[i] && fd[i])s2[++top2] = i;
//rep(i,1,top1)cout<<s1[i]<<" ";cout<<endl;
//rep(i,1,top1)cout<<s2[i]<<" ";cout<<endl;

	rep(i,1,top1)b[s2[i]] = s1[i];
	top1 = 0;rep(i,1,n)if(!fu[i] && !fd[i])s1[++top1] = i;
	if(top1 == 1){ 
		int x = s1[1];
		rep(i,1,n)if(b[i] == a[x]){
			b[i] = x;
			b[x] = a[x];
			break;
		}
	}
	else rep(i,1,top1)b[s1[i]] = i == top1 ? s1[1] : s1[i+1];
//rep(i,1,top1)cout<<s1[i]<<" ";cout<<endl;
	rep(i,1,n)write(b[i]),putchar(' ');putchar('\n'); 
}


int main(){
//	freopen("D.in","r",stdin);

	int Tc = read();
	while(Tc--)solve();

	return 0;

}