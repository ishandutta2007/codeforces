#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,k,ans,fa[100005];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d",&n,&k);
	ans=k;
	For(i,1,n) fa[i]=i;
	For(i,1,k){
		int x,y;
		scanf("%d%d",&x,&y);
		x=get(x); y=get(y);
		if (x!=y) fa[x]=y,ans--;
	}
	printf("%d\n",ans);
}