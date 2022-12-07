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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int N=105;
char s[N][N],ans[N][N];
int S,p,top,n,m,k,v[N],q[N];
void solve(){
	S=0;
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) For(j,1,m) S+=(s[i][j]=='R');
	For(i,1,k) v[i]=S/k+(i<=S%k);
	S=0; p=1;
	For(i,1,n)
		if (i&1)
			For(j,1,m){
				S+=(s[i][j]=='R');
				if (S>v[p]) S=1,++p;
				ans[i][j]=q[p];
			}
		else
			Rep(j,m,1){
				S+=(s[i][j]=='R');
				if (S>v[p]) S=1,++p;
				ans[i][j]=q[p];
			}
	For(i,1,n){
		For(j,1,m) putchar(ans[i][j]);
		puts("");
	}
}
int main(){
	For(i,'a','z') q[++top]=i;
	For(i,'A','Z') q[++top]=i;
	For(i,'0','9') q[++top]=i;
	int T;
	scanf("%d",&T);
	while (T--) solve();
}