#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=200005;
int cnt[N],n,ans;
char s[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
bool check(int x){
	For(i,1,x){
		int S=0;
		For(j,1,n/x)
			S^=s[j*x-x+i];
		if (S&1) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%s",&n,s+1);
	For(i,1,n) ++cnt[gcd(i,n)];
	For(i,1,n) if (cnt[i]&&check(i)) ans+=cnt[i];
	printf("%d\n",ans);
}