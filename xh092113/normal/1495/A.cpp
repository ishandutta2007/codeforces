#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define ld long double

const int N = 1e5;

namespace IO{
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

vector<int> x,y;
int n;

In ld sqr(ld x){return x * x;}
void solve(){
	x.resize(0);
	y.resize(0);
	n = read();
	for(rg int i = 1;i <= 2 * n;i++){
		int curx = read(),cury = read();
		if(curx == 0)y.push_back(abs(cury));
		else x.push_back(abs(curx));
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
//for(rg int i = 0;i < n;i++)cout<<x[i]<<" ";cout<<endl;
//for(rg int i = 0;i < n;i++)cout<<y[i]<<" ";cout<<endl;
	ld ans = 0;
	for(rg int i = 0;i < n;i++)ans += (ld)sqrt(sqr(x[i]) + sqr(y[i]));
	printf("%.9lf\n",(double)ans);
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();
	return 0;
}