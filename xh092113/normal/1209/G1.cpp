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
};
using namespace IO;

int n,a[N+5],lft[N+5],rht[N+5];
int sum[N+5],num[N+5];

In int calc(int l,int r){
	int mx = 0;
	for(rg int i = l;i <= r;i++){
		num[a[i]]++;
		if(num[a[i]] > mx)mx = num[a[i]];
	}
	return (r - l + 1) - mx;
}
void solve(){
	for(rg int i = 1;i <= N;i++)if(lft[i] || rht[i]){
		sum[lft[i]]++;
		sum[rht[i]]--;
	}
	for(rg int i = 1;i <= n;i++)sum[i] += sum[i-1];
	int last = 1,ans = 0;
	for(rg int i = 1;i <= n;i++)if(!sum[i])ans += calc(last,i),last = i + 1;
	write(ans),putchar('\n');
}

int main(){
//	freopen("CF1209G1.in","r",stdin);
//	freopen("CF1209G1.out","w",stdout);
	n = read();int q = read();
	for(rg int i = 1;i <= n;i++){
		a[i] = read();
		if(!lft[a[i]])lft[a[i]] = rht[a[i]] = i;
		else rht[a[i]] = i; 
	}
	solve();
	return 0;
}