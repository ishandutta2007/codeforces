#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=1005;
bitset<N> S[N];
vector<pii> e[N];
int fa[N*2],a[N],n;
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x); y=get(y);
	//assert(x!=y);
	fa[x]=y;
}
int main(){
	scanf("%d",&n);
	if (n==2){
		printf("1 2\n");
		return 0;
	}
	For(i,1,n){
		int cnt,x;
		scanf("%d",&cnt);
		For(j,1,cnt){
			scanf("%d",&x);
			S[x][i]=1;
		}
	}
	For(i,1,2*n) fa[i]=i;
	For(i,1,n) For(j,i+1,n){
		int val=(S[i]&S[j]).count();
		if (val==1) merge(i,j),merge(i+n,j+n);
		else if (val==2) merge(i,j+n),merge(i+n,j);
		else ++a[val],e[val].PB(pii(i,j));
	}
	if (a[n]==1ll*n*(n-1)/2)
		For(i,2,n) printf("%d %d\n",1,i);
	else if (a[n]){
		int x=-1,y=-1;
		For(i,1,n)
			if (S[i].count()==n)
				if (x==-1) x=i;
				else y=i;
		printf("%d %d\n",x,y);
		For(i,1,n)
			if (i!=x&&i!=y)
				if (get(i)==get(x)){
					printf("%d %d\n",i,y);
					merge(i+n,y); merge(i,y+n);
				}
				else{
					printf("%d %d\n",i,x);
					merge(i+n,x); merge(i,x+n);
				}
	}
	else{
		Rep(i,n,1)
			For(j,0,e[i].size()-1){
				int x=e[i][j].fi,y=e[i][j].se;
				if (get(x)!=get(y)){
					printf("%d %d\n",x,y);
					merge(x,y+n); merge(x+n,y);
				}
			}
	}
}