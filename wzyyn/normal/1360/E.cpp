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
int n;
char s[55][55];
int ok[55][55];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%s",s[i]+1);
	Rep(i,n,1) Rep(j,n,1){
		ok[i][j]=0;
		if (s[i][j]=='1'){
			ok[i][j]|=(i==n?1:ok[i+1][j]);
			ok[i][j]|=(j==n?1:ok[i][j+1]);
		}
		if (s[i][j]=='1')
			if (!ok[i][j])
				return puts("NO"),void(0);
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}