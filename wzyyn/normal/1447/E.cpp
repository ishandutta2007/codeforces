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

const int M=6000005;
int ch[M][2],nd=1,n,ans;
void insert(int v){
	int x=1;
	Rep(i,29,0){
		int c=(v>>i)&1;
		if (!ch[x][c]) ch[x][c]=++nd;
		x=ch[x][c];
	}
}
void dfs(int x,int v){
	ans=max(ans,v);
	if (ch[x][0]) dfs(ch[x][0],v+(ch[x][1]!=0));
	if (ch[x][1]) dfs(ch[x][1],v+(ch[x][0]!=0));
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		insert(x);
	}
	dfs(1,1);
	cout<<n-ans<<endl;
}