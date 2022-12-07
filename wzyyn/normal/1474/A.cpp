#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
int n;
char s[100005];
void solve(){
	int pref=-1;
	scanf("%d",&n);
	scanf("%s",s+1);
	For(i,1,n){
		int v=s[i]-'0';
		if (v+1==pref) pref=v,putchar('0');
		else putchar('1'),pref=v+1;
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}