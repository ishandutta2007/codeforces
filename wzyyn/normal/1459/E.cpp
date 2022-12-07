#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=1005;
int n;
int a[N][N];
int b[N][N];
int at[5],tag[5],c[5];
char s[N*N];
void solve(){
	scanf("%d%*d",&n);
	For(i,1,n) For(j,1,n)
		scanf("%d",&a[i][j]);
	at[0]=0; at[1]=1; at[2]=2;
	tag[0]=tag[1]=tag[2]=0;
	scanf("%s",s+1);
	for (int i=1;s[i];++i){
		if (s[i]=='R') tag[at[1]]=(tag[at[1]]+1)%n;
		if (s[i]=='L') tag[at[1]]=(tag[at[1]]+n-1)%n;
		if (s[i]=='D') tag[at[0]]=(tag[at[0]]+1)%n;
		if (s[i]=='U') tag[at[0]]=(tag[at[0]]+n-1)%n;
		if (s[i]=='I') swap(at[1],at[2]);
		if (s[i]=='C') swap(at[0],at[2]);
	}
	For(i,1,n) For(j,1,n){
		c[0]=(i+tag[0]+n-1)%n+1;
		c[1]=(j+tag[1]+n-1)%n+1;
		c[2]=(a[i][j]+tag[2]+n-1)%n+1;
		b[c[at[0]]][c[at[1]]]=c[at[2]];
	}
	For(i,1,n){
		For(j,1,n) printf("%d ",b[i][j]);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}