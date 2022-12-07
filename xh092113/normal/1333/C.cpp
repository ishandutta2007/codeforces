#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 2e5;

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
}
using namespace IO;

multiset<ll>S;

ll r[N+5];
ll s[N+5];

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	int n = read();
	for(rg int i = 1;i <= n;i++)s[i] = read();
	for(rg int i = 2;i <= n;i++)s[i] += s[i-1];
	int cur = 0;
	S.insert(s[0]);
	while(cur < n && !S.count(s[cur+1])){
		cur++;
		S.insert(s[cur]);
	}
	r[1] = cur;
	for(rg int i = 2;i <= n;i++){
		S.erase(S.lower_bound(s[i-2]));
		while(cur < n && !S.count(s[cur+1])){
			cur++;
			S.insert(s[cur]);
		}
		r[i] = cur;
	}
	ll ans = 0;
//for(rg int i = 1;i <= n;i++)write(r[i]),putchar(' ');putchar('\n');
	for(rg int i = 1;i <= n;i++)ans += r[i] - i + 1;
	cout << ans << endl;
	return 0;
}