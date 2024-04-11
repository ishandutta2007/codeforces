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
int n,a[N],q[N];
vector<int> e[N];
int dis[N];
void add(int x,int y){
	e[x].PB(y);
	//e[y].PB(x);
}
void build(){
	q[1]=1;
	int t=1;
	For(i,2,n){
		int la=-(1<<30);
		for (;t&&a[q[t]]<a[i];--t){
			if (a[q[t]]!=la) add(q[t],i);
			la=a[q[t]];
		}
		if (t) add(q[t],i);
		q[++t]=i;
	}
}
void SSSP(){
	For(i,1,n) dis[i]=-1;
	int h=0,t=1;
	q[1]=1; dis[1]=0;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (dis[i]==-1){
				dis[i]=dis[x]+1;
				q[++t]=i;
			}
	}
	cout<<dis[n]<<endl;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	build();
	For(i,1,n) a[i]*=-1;
	build();
	SSSP();
}