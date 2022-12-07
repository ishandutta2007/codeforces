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
#define double long double
using namespace std;
const int N=2005;
int n,f[N][N],a[30];
int v1[N][26],v2[N][26];
char s1[N],s2[N];
void solve(){
	scanf("%d%s%s",&n,s1+1,s2+1);
	memset(a,0,sizeof(a));
	For(i,1,n) ++a[s1[i]-'a'],--a[s2[i]-'a'];
	For(i,0,25) if (a[i]) return puts("-1"),void(0);
	For(i,1,n){
		memcpy(v1[i],v1[i-1],sizeof(v1[i]));
		memcpy(v2[i],v2[i-1],sizeof(v2[i]));
		v1[i][s1[i]-'a']++;
		v2[i][s2[i]-'a']++;
	}
	For(i,1,n) For(j,1,n){
		f[i][j]=max(f[i-1][j],f[i][j-1]);
		bool flag=(s1[i]==s2[j]);
		For(k,0,25) if (v1[i][k]>v2[j][k]) flag=0;
		if (flag) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
	}
	cout<<n-f[n][n]<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
1
8
aaazyaaa
yaaaaaaz
*/