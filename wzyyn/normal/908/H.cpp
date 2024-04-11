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
const int N=50;
int n,fa[N],p[N];
int sz[N],id[N];
int co[N],e[N][N];
char s[N][N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]); 
}
int main(){
	scanf("%d",&n);
	For(i,1,n) fa[i]=i;
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) For(j,1,n)
		if (s[i][j]=='A') fa[get(i)]=get(j);
	For(i,1,n) For(j,1,n)
		if (s[i][j]=='X'&&get(i)==get(j))
			return puts("-1"),0; 
	For(i,1,n) ++sz[get(i)];
	For(i,1,n) if (get(i)==i&&sz[i]!=1) id[i]=++*id;
	For(i,1,n) For(j,1,n)
		if (s[i][j]=='X') e[id[get(i)]][id[get(j)]]=1;
	int ans=*id;
	For(i,1,*id) p[i]=i;
	For(T,1,1000){
		random_shuffle(p+1,p+*id+1);
		memset(co,0,sizeof(co));
		int col=1;
		For(i,2,*id){
			int sta=0;
			For(j,1,i-1)
				if (e[p[j]][p[i]])
					sta|=1<<co[p[j]];
			sta^=(1<<col)-1;
			if (!sta) co[p[i]]=col++;
			else
				for (;;){
					co[p[i]]=rand()%col;
					if (sta&(1<<co[p[i]])) break;
				}
		}
		ans=min(ans,col);
	}
	printf("%d\n",ans+n-1);
}