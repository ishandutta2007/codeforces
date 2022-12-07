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

int n,m;
int A[N+5],B[N+5],a[N+5],b[N+5];
int suf[N+5];
set<int> SB;

int Solve(int a[],int b[],int n,int m){
	SB.clear();
	for(rg int i = 1;i < n + 1 - i;i++)swap(a[i],a[n+1-i]);
	for(rg int i = 1;i < m + 1 - i;i++)swap(b[i],b[m+1-i]);
//cout<<"Solve: n="<<n<<" m="<<m<<endl;
//for(rg int i = 1;i <= n;i++)cout<<a[i]<<" ";cout<<endl;
//for(rg int i = 1;i <= m;i++)cout<<b[i]<<" ";cout<<endl;
	for(rg int i = 1;i <= m;i++)SB.insert(b[i]);
	if(!n || !m)return 0;
	int c = 0,r = 0;
	suf[n+1] = 0;
	int ans = 0;
	for(rg int i = n;i >= 1;i--)suf[i] = suf[i+1] + SB.count(a[i]);
	for(rg int i = 1;i <= m;i++){ // move 0 to b[i] - 1
		int p = b[i] - 1;
		while(c < n && a[c+1] <= p + c + 1)c++;
		while(r < m && b[r+1] <= p + c)r++;
		ans = max(ans,max(0,r-i+1) + suf[c+1]);
	}
//cout<<"ans="<<ans<<endl;
	return ans;
}
void solve(){
	int curn = 0,curm = 0;
	n = read(),m = read();
	for(rg int i = 1;i <= n;i++)A[i] = read();
	for(rg int i = 1;i <= m;i++)B[i] = read();
	int ans = 0;
	for(rg int i = 1;i <= n;i++)if(A[i] < 0)a[++curn] = -A[i];
	for(rg int i = 1;i <= m;i++)if(B[i] < 0)b[++curm] = -B[i];
	ans += Solve(a,b,curn,curm);
	curn = 0,curm = 0;
	for(rg int i = n;i >= 1;i--)if(A[i] > 0)a[++curn] = A[i];
	for(rg int i = m;i >= 1;i--)if(B[i] > 0)b[++curm] = B[i];
	ans += Solve(a,b,curn,curm);
//cout<<"ansansans="<<ans<<endl;
	write(ans),putchar('\n');
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	int Tc = read();
	while(Tc--){
		solve();
	}
	return 0;
}