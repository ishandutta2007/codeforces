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
const int N=100005;
int n,m,Q;
char s1[N],s2[N],s3[N],s4[N];
struct Lover{
	int t[N*4][2],rev[N*4],n;
	void build(int k,int l,int r,char *s){
		t[k][0]=t[k][1]=rev[k]=0;
		if (l==r){
			t[k][s[l]=='R']=1;
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid,s);
		build(k*2+1,mid+1,r,s);
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
	void change(int k,int l,int r,int x,int y){
		if (x<=l&&r<=y) return rever(k);
		pushdown(k);
		int mid=(l+r)/2;
		if (x<=mid) change(k*2,l,mid,x,y);
		if (y>mid) change(k*2+1,mid+1,r,x,y);
		t[k][0]=t[k*2][0]+t[k*2+1][0];
		t[k][1]=t[k*2][1]+t[k*2+1][1];
	}
	void build(int _n,char *s){
		n=_n;
		build(1,1,n,s);
	}
	void change(int l,int r){
		change(1,1,n,l,r);
	}
	int query(int x){
		return t[1][x];
	}
};
struct noder{
	int a[2][2];
	noder(){
		memset(a,1,sizeof(a));
	}
};
noder Mul(noder a,noder b,int v){
	noder c;
	For(c1,0,1) For(c2,0,1) For(c3,0,1) For(c4,0,1)
		c.a[c1][c4]=min(c.a[c1][c4],a.a[c1][c2]+b.a[c3][c4]+(c2^c3)*v);
	return c;
}
struct Fucker{
	Lover L,R;
	noder t[N*4][4];
	int rev[N*4],n,m,val;
	void pushup(int k){
		For(c1,0,3) t[k][c1]=Mul(t[k*2][c1],t[k*2+1][c1],m);
	}
	void rever(int k,int c){
		rev[k]^=c;
		int p1=0,p2=(c==1?2:1);
		swap(t[k][p1],t[k][p1^c]);
		swap(t[k][p2],t[k][p2^c]);
	}
	void pushdown(int k){
		if (rev[k]){
			rever(k*2,rev[k]);
			rever(k*2+1,rev[k]);
			rev[k]=0;
		}
	}
	void build(int k,int l,int r,char *s1,char *s2){
		if (l==r){
			For(c,0,3){
				int v1=(s1[l]=='R')^((c&1)==1);
				int v2=(s2[l]=='R')^((c&2)==2);
				t[k][c].a[0][0]=(v1==1)+(v2==1);
				t[k][c].a[1][1]=(v1==0)+(v2==0);
			}
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid,s1,s2);
		build(k*2+1,mid+1,r,s1,s2);
		pushup(k);
	}
	void change(int k,int l,int r,int x,int y,int c){
		if (x<=l&&r<=y) return rever(k,c);
		pushdown(k);
		int mid=(l+r)/2;
		if (x<=mid) change(k*2,l,mid,x,y,c);
		if (y>mid) change(k*2+1,mid+1,r,x,y,c);
		pushup(k);
	}
	void init(char *s1,char *s2,char *s3,char *s4,int _m,int _n){
		n=_n; m=_m; val=1<<30;
		L.build(m,s1); R.build(m,s2);
		build(1,1,n,s3,s4);
		For(c1,0,1) For(c2,0,1)
			val=min(val,t[1][0].a[c1][c2]+L.query(c1^1)+R.query(c2^1));
	}
	void change(int c,int l,int r){
		val=1<<30;
		if (c==0) L.change(l,r);
		else if (c==1) R.change(l,r);
		else change(1,1,n,l,r,1<<(c-2));
		For(c1,0,1) For(c2,0,1)
			val=min(val,t[1][0].a[c1][c2]+L.query(c1^1)+R.query(c2^1));
		//cout<<val<<' ';//endl;
	}
}T1,T2;
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	scanf("%s%s%s%s",s1+1,s2+1,s3+1,s4+1);
	T1.init(s1,s2,s3,s4,n,m);
	T2.init(s3,s4,s1,s2,m,n);
	printf("%d\n",min(T1.val,T2.val));
	while (Q--){
		char s[5]; int l,r;
		scanf("%s%d%d",s+1,&l,&r);
		int type;
		if (s[1]=='L') type=0;
		if (s[1]=='R') type=1;
		if (s[1]=='U') type=2;
		if (s[1]=='D') type=3;
		T1.change(type,l,r);
		T2.change(type^2,l,r);
		printf("%d\n",min(T1.val,T2.val));
	}
}