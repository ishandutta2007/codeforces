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
const int N=200005;
int n,k;
int c[N][26],fa[N];
char s[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x); y=get(y);
	if (x==y) return;//continue;
	For(i,0,25) c[x][i]+=c[y][i];
	fa[y]=x;
}
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) For(j,0,25) c[i][j]=0;
	scanf("%s",s+1);
	For(i,1,n) c[i][s[i]-'a']++,fa[i]=i;
	For(i,1,n/2) merge(i,n-i+1);
	For(i,1,n-k) merge(i,i+k);
	int ans=0;
	For(i,1,n) if (get(i)==i){
		int sum=0,mx=0;
		For(j,0,25){
			sum+=c[i][j];
			mx=max(mx,c[i][j]);
		}
		ans+=sum-mx;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}