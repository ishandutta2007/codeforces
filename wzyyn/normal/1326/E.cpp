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
int n,p[N],q[N],pos[N];
int tg[N*4],mn[N*4];
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y) return tg[k]+=v,mn[k]+=v,void(0);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	mn[k]=min(mn[k*2],mn[k*2+1])+tg[k];
}
int ask(int k,int l,int r,int p){
	if (l==r) return tg[k];
	int mid=(l+r)/2;
	if (p<=mid) return ask(k*2,l,mid,p)+tg[k];
	return ask(k*2+1,mid+1,r,p)+tg[k];
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&p[i]),pos[p[i]]=i;
	For(i,1,n) scanf("%d",&q[i]);
	int at=n;
	For(i,1,n){
		printf("%d ",at);
		change(1,0,n,q[i],n,-1);
		for (;at;--at){
			change(1,0,n,pos[at],n,1);
			//cout<<ask(1,1,n,n)<<' '<<mn[1]<<endl; 
			if (ask(1,0,n,n)!=mn[1]) break; 
		}
		
		change(1,0,n,pos[at],n,-1);
	}
}
/*
6
5 6 4 3 2 1
1 2 3 4 5 6

1 0 1 1 1 1

*/