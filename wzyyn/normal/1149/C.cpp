#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=1000005;
struct node{
	int a[3][3];
	node(){
		memset(a,233,sizeof(a));
	}
}t[N*6];
node operator +(const node &a,const node &b){
	node ans;
	For(i,0,2) For(j,i,2)
		ans.a[i][j]=max(a.a[i][j],b.a[i][j]);
	For(i,0,2) For(j,i,2) For(k,j+1,2)
		ans.a[i][k]=max(ans.a[i][k],a.a[i][j]+b.a[j+1][k]);
	return ans;
}
int tg[N*6],d[N*6];
char s[N*2];
int n,Q;
void build(int k,int l,int r){
	if (l==r){
		t[k].a[0][0]=d[l];
		t[k].a[1][1]=-2*d[l];
		t[k].a[2][2]=d[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void update(int k,int v){
	tg[k]+=v;
	For(i,0,2) For(j,i,2)
		t[k].a[i][j]+=(j-i+1-(j==0||i==2?0:3))*v;		
}
void pushdown(int k){
	if (!tg[k]) return;
	update(k*2,tg[k]);
	update(k*2+1,tg[k]);
	tg[k]=0;
}
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		update(k,v);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if	(x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	t[k]=t[k*2]+t[k*2+1];
}
int main(){
	scanf("%d%d%s",&n,&Q,s+1);
	For(i,1,2*n) d[i]=d[i-1]+(s[i]=='('?1:-1);
	build(1,0,2*n);
	printf("%d\n",t[1].a[0][2]);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		if (s[x]!=s[y]){
			change(1,0,2*n,x,y-1,s[x]=='('?-2:2);
			swap(s[x],s[y]);
		}
		printf("%d\n",t[1].a[0][2]);
	}
}