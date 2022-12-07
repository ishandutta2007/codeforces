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
const int inf=1<<29;
struct Mat{
	int a[5][5];
	Mat(){
		memset(a,40,sizeof(a));
	}
	void I(){
		memset(a,40,sizeof(a));
		For(i,0,4) a[i][i]=0;
	}
	Mat operator *(const Mat &b)const{
		Mat c;
		For(i,0,4) For(j,i,4) For(k,j,4)
			c.a[i][k]=min(c.a[i][k],a[i][j]+b.a[j][k]);
		return c;
	}
}t[N*4];
int n,Q;
char s[N];
void build(int k,int l,int r){
	if (l==r){
		t[k].I();
		if (s[l]=='2') t[k].a[0][1]=0,t[k].a[0][0]=1;
		if (s[l]=='0') t[k].a[1][2]=0,t[k].a[1][1]=1;
		if (s[l]=='1') t[k].a[2][3]=0,t[k].a[2][2]=1;
		if (s[l]=='7') t[k].a[3][4]=0,t[k].a[3][3]=1;
		if (s[l]=='6') t[k].a[3][3]=1,t[k].a[4][4]=1;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]*t[k*2+1];
}
Mat ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)*ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d%s",&n,&Q,s+1);
	build(1,1,n);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int v=ask(1,1,n,l,r).a[0][4];
		printf("%d\n",v>inf?-1:v);
	}
}