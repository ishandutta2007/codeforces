#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)
#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)

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
};
using namespace IO;

int n;
int a[N+5];
char s[N+5],t[N+5],st[N+5];
vector<int> p0,p1;

void solve(){
	p0.resize(0);
	p1.resize(0);
	n = read();
	scanf("%s",st + 1);
	rep(i,1,n){
		a[i] = st[i] - '0';
		if(a[i] == 0)p0.push_back(i);
		else p1.push_back(i);
	}	
	if(a[1] != 1 || a[n] != 1 || (p0.size()&1)){
		puts("NO");return;
	}
	else{
		for(rg int i = 0;i < p0.size();i++){
			if(i & 1)s[p0[i]] = '(',t[p0[i]] = ')';
				else t[p0[i]] = '(',s[p0[i]] = ')';	
		}
		for(rg int i = 0;i < p1.size();i++){
			if(i < p1.size() / 2)s[p1[i]] = t[p1[i]] = '(';
			else s[p1[i]] = t[p1[i]] = ')';
		}
	}
	puts("YES");
	for(rg int i = 1;i <= n;i++)putchar(s[i]);putchar('\n');
	for(rg int i = 1;i <= n;i++)putchar(t[i]);putchar('\n');
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();
	return 0;
}