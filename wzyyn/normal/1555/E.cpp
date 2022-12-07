#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=1000005;
int t[1<<21|5];
int tg[1<<21|5];
struct node{
	int l,r,v;
	bool operator <(const node &a)const{
		return v<a.v;
	}
}op[N];
int n,m;
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		t[k]+=v; tg[k]+=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	t[k]=tg[k]+min(t[k*2],t[k*2+1]);
}
int main(){
	scanf("%d%d",&n,&m);	
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&op[i].l,&op[i].r,&op[i].v);
	sort(op+1,op+n+1);
	int l=1,ans=1<<30;
	for (int r=1;r<=n;r++){
		change(1,1,m-1,op[r].l,op[r].r-1,1);
		for (;t[1];){
			ans=min(ans,op[r].v-op[l].v);
			change(1,1,m-1,op[l].l,op[l].r-1,-1);
			++l;
		}
	}
	cout<<ans<<endl;
}