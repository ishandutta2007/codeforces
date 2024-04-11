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
const int N=100005;
int n,m,ans;
vector<int> e[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n) ans+=e[i].size()&1;
	For(i,1,n) if (e[i].size()==2){
		int x=e[i][0],y=e[i][1];
		if (x==y) e[x].resize(0),ans+=2;
		else{
			e[x][e[x][0]!=i]=y;
			e[y][e[y][0]!=i]=x;
		}
	}
	printf("%d %d",ans/2,m);
}