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
const int N=5005;
int n,m,n1,n2,n3;
int fa[N],v[N],sz[N][2];
bitset<N> f[N];
int q[N],col[N];
int get(int x){
	if (x==fa[x]) return x;
	int y=get(fa[x]);
	v[x]^=v[fa[x]];
	return fa[x]=y;   
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&n1,&n2,&n3);
	For(i,1,n) fa[i]=i,v[i]=0;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		int px=get(x),py=get(y);
		//cout<<px<<' '<<py<<' '<<v[y]<<' '<<v[x]<<endl;
		if (px!=py) fa[py]=px,v[py]=v[x]^v[y]^1;
		else if (v[y]^v[x]^1) return puts("NO"),0;
	}
	For(i,1,n){
		get(i);
		++sz[get(i)][v[i]];
	}
	*q=0; f[0][0]=1;
	For(i,1,n) if (get(i)==i){
		q[++*q]=i;
		//cout<<i<<' '<<sz[i][0]<<' '<<sz[i][1]<<endl;
		f[*q]|=f[(*q)-1]<<sz[i][0];
		f[*q]|=f[(*q)-1]<<sz[i][1];
	}
	if (!f[*q][n2])
		return puts("NO"),0;
	puts("YES");
	int pos=n2;
	Rep(i,(*q),1)
		if (pos>=sz[q[i]][0]&&f[i-1][pos-sz[q[i]][0]])
			col[q[i]]=0,pos-=sz[q[i]][0];
		else col[q[i]]=1,pos-=sz[q[i]][1];
	For(i,1,n)
		if (v[i]==col[get(i)]) printf("2");
		else if (n1) printf("1"),--n1;
		else printf("3"),--n3;
}