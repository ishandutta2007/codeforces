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
struct Fucker{
	int t[N*4][2][2],n,m,val;
	int v[N][2],L[2],R[2];
	void pushup(int k){
		int ls=k*2,rs=ls|1;
		memset(t[k],1,sizeof(t[k]));
		For(c1,0,1) For(c2,0,1) For(c3,0,1) For(c4,0,1)
			t[k][c1][c4]=min(t[k][c1][c4],t[ls][c1][c2]+t[rs][c3][c4]+(c2^c3)*m);
	}
	void build(int k,int l,int r){
		if (l==r){
			t[k][0][0]=v[l][1];
			t[k][1][1]=v[l][0];
			t[k][0][1]=t[k][1][0]=1e8;
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
		pushup(k);
	}
	void change(int k,int l,int r,int p){
		if (l==r){
			t[k][0][0]=v[l][1];
			t[k][1][1]=v[l][0];
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
		pushup(k);
	}
	void init(char *s1,char *s2,char *s3,char *s4,int _m,int _n){
		n=_n; m=_m;
		For(i,1,m) (s1[i]=='R'?++L[0]:++L[1]);
		For(i,1,m) (s2[i]=='R'?++R[0]:++R[1]);
		For(i,1,n) (s3[i]=='R'?++v[i][0]:++v[i][1]);
		For(i,1,n) (s4[i]=='R'?++v[i][0]:++v[i][1]);
		build(1,1,n); val=1<<30;
		For(c1,0,1) For(c2,0,1)
			val=min(val,t[1][c1][c2]+L[c1^1]+R[c2^1]);
		//cout<<val<<endl;
	}
	void change(int p,int c,int f){
		val=1<<30;
		if (c==0) L[f]--,L[f^1]++;
		else if (c==1) R[f]--,R[f^1]++;
		else{
			v[p][f]--; v[p][f^1]++;
			change(1,1,n,p);
		}
		For(c1,0,1) For(c2,0,1)
			val=min(val,t[1][c1][c2]+L[c1^1]+R[c2^1]);
	}
}T1,T2;
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	scanf("%s%s%s%s",s1+1,s2+1,s3+1,s4+1);
	T1.init(s1,s2,s3,s4,n,m);
	T2.init(s3,s4,s1,s2,m,n);
	printf("%d\n",min(T1.val,T2.val));
}