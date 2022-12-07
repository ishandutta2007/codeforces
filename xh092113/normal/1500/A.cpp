#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define mp make_pair

const int N = 2e5;
const int W = 5e6;

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

int n,a[N+5],m1[W+5],m2[W+5],m3[W+5],m4[W+5];
pair<int,int> ans[W+5];

void print(int x,int y,int z,int w){
	puts("YES");
	cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
}
void solve(){
	for(rg int i = 1;i <= n;i++)if(m4[a[i]]){
		print(m1[a[i]],m2[a[i]],m3[a[i]],m4[a[i]]);
		return;
	}
	int p = 0;
	for(rg int i = 1;i <= n;i++)if(m2[a[i]]){
		if(!p)p = i;
		else {
			print(m1[a[p]],m1[a[i]],m2[a[p]],m2[a[i]]);
			return;
		}
	}
	if(p){
		for(rg int i = 1;i <= n;i++){
			int ex = a[p] + a[p] - a[i];
			if(ex == a[i])continue;
			if(m1[ex]){
				print(m1[ex],m1[a[i]],m1[a[p]],m2[a[p]]);
				return;
			}
		}
	}
	for(rg int i = 1;i <= n;i++){
		for(rg int j = i + 1;j <= n;j++){
			int sum = a[i] + a[j];
			if(ans[sum] != mp(0,0)){
				print(m1[a[i]],m1[a[j]],ans[sum].first,ans[sum].second);
				return;
			}
			else{
				ans[sum] = make_pair(m1[a[i]],m1[a[j]]);
			}
		}
	}
	puts("NO");
}

int main(){
//	freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	n = read();int nn = 0;
	for(rg int i = 1;i <= n;i++){
		int x = read();
		if(!m1[x])m1[x] = i,a[++nn] = x;
		else if(!m2[x])m2[x] = i;
		else if(!m3[x])m3[x] = i;
		else if(!m4[x])m4[x] = i;
	}
	n = nn;
	solve();
	return 0;
}