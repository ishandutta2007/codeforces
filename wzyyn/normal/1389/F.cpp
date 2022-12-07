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
const int N=400005;
int n,q[N*2],l[N],r[N];
int g[N][2],f[N];
vector<int> vec[N];
struct node{
	int t[N*4],tg[N*4];
	void change(int k,int l,int r,int x,int y,int v){
		if (x<=l&&r<=y){
			t[k]+=v;
			tg[k]+=v;
			return;
		}
		int mid=(l+r)/2;
		if (x<=mid) change(k*2,l,mid,x,y,v);
		if (y>mid) change(k*2+1,mid+1,r,x,y,v);
		t[k]=max(t[k*2],t[k*2+1])+tg[k];
	}
}t[2];
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d%d",&l[i],&r[i],&f[i]);
		q[++*q]=l[i]; q[++*q]=r[i]; --f[i];
	}
	sort(q+1,q+*q+1);
	For(i,1,n){
		l[i]=lower_bound(q+1,q+*q+1,l[i])-q;
		r[i]=lower_bound(q+1,q+*q+1,r[i])-q;
		vec[r[i]].PB(i);
	}
	For(i,1,*q){
		for (auto j:vec[i])
			t[f[j]].change(1,0,*q,0,l[j]-1,1);
		g[n][0]=t[0].t[1];
		g[n][1]=t[1].t[1];
		t[1].change(1,0,*q,i,i,g[n][0]);
		t[0].change(1,0,*q,i,i,g[n][1]);
	}
	cout<<max(g[n][0],g[n][1])<<endl;
}