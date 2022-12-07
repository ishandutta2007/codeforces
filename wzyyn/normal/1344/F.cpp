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
const int N=2005;
int n,k,top;
int vis[N],res[N];
bitset<N> B[2][N];
bitset<N> f[N];
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) B[0][i][i*2-1]=B[1][i][i*2]=1;
	For(i,1,k){
		string s;
		int cnt,x;
		cin>>s>>cnt;
		while (cnt--){
			int x;
			scanf("%d",&x);
			if (s=="RB") swap(B[0][x],B[1][x]);
			if (s=="RY") B[1][x]^=B[0][x];
			if (s=="YB") B[0][x]^=B[1][x];
			if (s=="mix") f[top+1]^=B[0][x],f[top+2]^=B[1][x];
		}
		if (s=="mix"){
			cin>>s;
			f[top+1][2*n+1]=(s[0]!='B'&&s[0]!='W');
			f[top+2][2*n+1]=(s[0]!='R'&&s[0]!='W');
			top+=2;
		}
	}
	top=max(top,2*n);
	For(i,1,2*n){
		int p=-1;
		For(j,1,top)
			if (!vis[j]&&f[j][i])
				p=j;
		if (p==-1) continue;
		swap(f[p],f[i]); vis[i]=1;
		For(j,1,top)
			if (j!=i&&f[j][i])
				f[j]^=f[i];
	}
	For(i,1,top)
		if (!vis[i]&&f[i][2*n+1])
			return puts("NO"),0;
	Rep(i,2*n,1)
		if (vis[i]){
			res[i]=f[i][2*n+1];
			For(j,i+1,2*n) if (f[i][j]) res[i]^=res[j];
		}
	puts("YES");
	For(i,1,n){
		int id=res[i*2-1]*2+res[2*i];
		string tmp=".BRY";
		printf("%c",tmp[id]);
	}
}
/*
R:10
B:01
Y:11
*/