#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
int n;
uint f[N*2];
char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	if (n&1) return puts("0"),0;
	int sum=0;
	For(i,1,n) sum+=(s[i]!='?');
	if (sum*2>n) return puts("0"),0;
	uint *g=f+n; g[0]=1;
	For(i,1,n){
		g=g-1;
		if (s[i]=='?'){
			int lim=min(i,n-i);
			for (int j=(i&1);j<=lim;j+=8){
				g[j]+=g[j+2];
				g[j+2]+=g[j+4];
				g[j+4]+=g[j+6];
				g[j+6]+=g[j+8]; 
			}
		}
	}
	uint ans=g[0];
	For(i,1,n/2-sum) ans*=25;
	printf("%u",ans);
}