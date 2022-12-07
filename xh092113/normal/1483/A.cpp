#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

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

vector<int> fr[N+5];
vector<int> t[N+5];
int n,m,limit;
int ans[N+5];
vector<int> pos;
bool vip[N+5];

void print(){
	puts("YES");
	for(rg int i = 1;i <= m;i++)write(ans[i]),putchar(' ');
	putchar('\n');
}
In bool check(int x){
	int d = 0;
	for(auto i : t[x])if(fr[i].size() == 1)d++;
	if(d > limit)return 0;
	else{
		pos.resize(0);
		for(auto i : t[x])if(fr[i].size() == 1)pos.push_back(i);
		for(auto i : t[x]){
			if(pos.size() == limit)break;
			if(fr[i].size() > 1)pos.push_back(i);
		}
		for(auto i : pos)vip[i] = 1;
		for(rg int i = 1;i <= m;i++){
			if(!vip[i]){
				if(fr[i][0] != x)ans[i] = fr[i][0];
				else ans[i] = fr[i][1];
			}
			else ans[i] = x;
		}
		for(auto i : pos)vip[i] = 0;
		return 1;
	}
}
void solve(){
	n = read(),m = read();
	for(rg int i = 1;i <= n;i++)t[i].resize(0);
	for(rg int i = 1;i <= m;i++){
		int k = read();
		fr[i].resize(0);
		for(rg int j = 1;j <= k;j++){
			int x = read();
			t[x].push_back(i);
			fr[i].push_back(x);
		}
	}
	bool b = 0;
	limit = ceil(0.5 * m);
	for(rg int i = 1;i <= n;i++)if(t[i].size() > limit){
		if(check(i)){print();return;}
		b = 1;
	}	
	if(!b){
		for(rg int i = 1;i <= m;i++)ans[i] = fr[i][0];
		print();return;
	}
	puts("NO");return;
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--){
		solve();
	}
	return 0;
}