#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=200005;
int n,m;
char a[N],s[N];
void solve(){
	scanf("%d%d",&n,&m);
	for (int j=1;j<=m;j++) a[j]=0;
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) a[j]+=s[j];
	}
	for (int i=1;i<n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) a[j]-=s[j];
	}
	for (int j=1;j<=m;j++)
		putchar(a[j]);
	puts("");
	fflush(stdout);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}