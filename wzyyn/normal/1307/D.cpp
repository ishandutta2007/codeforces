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
int n,m,k,a[N];
int q[N],d1[N],d2[N];
vector<int> e[N];
void SSSP(int S,int *d){
	For(i,1,n) d[i]=-1;
	int h=0,t=1;
	q[1]=S; d[S]=0;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (d[i]==-1){
				q[++t]=i;
				d[i]=d[x]+1;
			}
	}
}
bool cmp(int x,int y){
	return d1[x]-d1[y]<d2[x]-d2[y];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,k) scanf("%d",&a[i]);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	SSSP(1,d1);
	SSSP(n,d2);
	sort(a+1,a+k+1,cmp);
	int mx=-(1<<30),ans=0;
	For(i,1,k){
		//cout<<a[i]<<' '<<d1[a[i]]<<' '<<d2[a[i]]<<endl;
		ans=max(ans,mx+d2[a[i]]);
		mx=max(mx,d1[a[i]]);
	}
	mx=-(1<<30);
	Rep(i,k,1){
		ans=max(ans,mx+d1[a[i]]);
		mx=max(mx,d2[a[i]]);
	}
	printf("%d\n",min(ans+1,d1[n]));
}
/*
d1[i]+d2[i]
*/