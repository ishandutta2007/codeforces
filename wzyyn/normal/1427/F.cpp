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
int n,nd,top;
int vi[N],id[N],q[N];
int fa[N],vis[N],ind[N];
int fl[N];
int main(){
	scanf("%d",&n);
	For(i,1,3*n){
		int x;
		scanf("%d",&x);
		vi[x]=1;
	}
	For(i,1,n*6){
		q[++top]=i;
		if (top==1||vi[q[top-1]]!=vi[i])
			id[i]=++nd,fa[nd]=id[q[top-1]],fl[nd]=vi[i];
		else{
			id[i]=id[q[top-1]];
			if (top>=3&&id[q[top-1]]==id[q[top-2]])	
				top-=3;
		}
	}
	//For(i,1,n*6) cout<<id[i]<<' '; cout<<endl;
	For(i,1,nd)
		++ind[fa[i]];
	assert(!top);
	For(i,1,2*n){
		int cho=-1;
		For(j,1,2*n){
			if (vis[j]) continue;
			if (fl[j]!=i%2) continue;
			if (ind[j]) continue;
			cho=j;
			if (i%2||fa[j]) break;
		}
		assert(cho!=-1);
		vis[cho]=1;
		--ind[fa[cho]];
		For(j,1,6*n)
			if (id[j]==cho)
				printf("%d ",j);
		puts("");
	}
}