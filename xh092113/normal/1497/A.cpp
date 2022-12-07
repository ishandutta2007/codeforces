#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 100;

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

int n,b[N+5];
multiset<int> s;

void solve(){
	s.clear();
	n = read();for(rg int i = 1;i <= n;i++)s.insert(read());
	int cnt = 0;
	for(rg int i = 0;i <= n;i++){
		if(s.count(i)){
			multiset<int> :: iterator it = s.find(i);
			s.erase(it);
			b[++cnt] = i;
		}
		else break;
	} 
	for(auto x : s)b[++cnt] = x;
	for(rg int i = 1;i <= n;i++)write(b[i]),putchar(' ');putchar('\n');
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();
	return 0;
}