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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=(1<<20)|5;
int n,q;
char s[N];
struct Noder{
	int a[4][4];
	Noder(){
		memset(a,233,sizeof(a));
	}
	Noder operator +(const Noder &b)const{
		Noder c;
		For(i,0,3) For(j,i,3) For(k,j,3)
			c.a[i][k]=max(c.a[i][k],a[i][j]+b.a[j][k]);
		return c;
	}
}t[N][2];
int rev[N];
void pushup(int k){
	t[k][0]=t[k*2][0]+t[k*2+1][0];
	t[k][1]=t[k*2][1]+t[k*2+1][1];
}
void rever(int k){
	rev[k]^=1;
	swap(t[k][0],t[k][1]);
} 
void pushdown(int k){
	if (rev[k]){
		rever(k*2);
		rever(k*2+1);
		rev[k]=0;
	} 
} 
void build(int k,int l,int r){
	if (l==r){
		t[k][0].a[0][3]=1;
		t[k][0].a[0][2]=1;
		t[k][0].a[0][1]=1;
		t[k][0].a[0][0]=0;
		t[k][0].a[1][3]=1;
		t[k][0].a[1][1]=1;
		t[k][0].a[1][2]=1;
		t[k][0].a[2][2]=-1e9;
		t[k][0].a[2][3]=-1e9;
		t[k][0].a[3][3]=0;
		
		t[k][1].a[0][3]=1;
		t[k][1].a[0][2]=1;
		t[k][1].a[0][1]=0;
		t[k][1].a[0][0]=0;
		t[k][1].a[1][3]=-1e9;
		t[k][1].a[1][1]=-1e9;
		t[k][1].a[1][2]=1;
		t[k][1].a[2][2]=1;
		t[k][1].a[2][3]=1;
		t[k][1].a[3][3]=0;
		
		if (s[l]=='<') swap(t[k][0],t[k][1]);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return rever(k);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y);
	if (y>mid) change(k*2+1,mid+1,r,x,y);
	pushup(k);
}
Noder ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return t[k][0];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	build(1,1,n);
	while (q--){
		int l,r;
		scanf("%d%d",&l,&r);
		change(1,1,n,l,r);
		Noder tmp=ask(1,1,n,l,r);
		printf("%d\n",tmp.a[0][3]);
	}
}
/*
>>><<<
*/