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
const int N=300005;
int n,dia;
int dep[N],fa[N][20];
vector<int> p1,p2;
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,18) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,18,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void update(int x){
	int d1=(p1.size()?dis(x,p1[0]):-1);
	int d2=(p2.size()?dis(x,p2[0]):-1);
	//cout<<d1<<' '<<d2<<' '<<(p1.size()?p1[0]:-1)<<' '<<(p2.size()?p2[0]:-1)<<endl;
	if (d1>dia){
		for (auto i:p2) if (dis(x,i)==d1) p1.PB(i);
		++dia; p2.resize(0); p2.PB(x);
	}
	else if (d2>dia){
		for (auto i:p1) if (dis(x,i)==d2) p2.PB(i);
		++dia; p1.resize(0); p1.PB(x); 
	}
	else if (d1==dia) p2.PB(x);
	else if (d2==dia) p1.PB(x);
}
int main(){
	scanf("%d",&n);
	dia=0; p1.PB(1);
	For(i,2,n+1){
		scanf("%d",&fa[i][0]);
		dep[i]=dep[fa[i][0]]+1;
		For(j,1,18) fa[i][j]=fa[fa[i][j-1]][j-1];
		update(i);
		printf("%d\n",p1.size()+p2.size());
	}
}