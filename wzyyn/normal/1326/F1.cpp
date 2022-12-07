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
struct state{
	int a[20];
	bool operator <(const state &b)const{
		For(i,0,19)
			if (a[i]!=b.a[i])
				return a[i]<b.a[i];
		return 0;
	}
}sta[1005];
map<state,int> mp;
int n,top,bit[1<<20];
ll f[20][20],tr[20][20];
ll g[1<<20],h[1<<20],val[20];
char s[20][20];
void divide(int n,int d,state tmp){
	if (!n){
		sta[++top]=tmp;
		mp[tmp]=top;
		return;
	}
	if (n<d) return;
	for (;n>=0;n-=d){
		divide(n,d+1,tmp);
		++tmp.a[d];
	}
}
int main(){
	scanf("%d",&n);
	state tmp;
	memset(tmp.a,0,sizeof(tmp.a));
	divide(n,1,tmp);
	For(i,0,n-1) scanf("%s",s[i]);
	For(i,0,n-1) For(j,0,n-1) tr[i][j]=(s[i][j]=='0'?0:1);
	For(i,0,(1<<n)-1){
		bit[i]=bit[i/2]+(i&1);
		memset(f,0,sizeof(f));
		For(j,0,n-1) if (i&(1<<j)) f[0][j]=1;
		For(j,1,n) For(k,0,n-1) if (i&(1<<k))
			For(l,0,n-1) if (i&(1<<l))
				if (tr[k][l]==0) f[j][l]+=f[j-1][k];
		memset(val,0,sizeof(val));
		For(j,0,n) For(k,0,n-1) val[j]+=f[j][k];
		//For(j,0,n) printf("%d %d %d\n",i,j,val[j]);
		For(j,1,top){
			ll v=1;
			For(k,1,n) For(l,1,sta[j].a[k]) v*=val[k-1];
			if ((n-bit[i])&1) v=-v;
			g[j]+=v;
		}
	}
	For(i,0,(1<<(n-1))-1){
		memset(tmp.a,0,sizeof(tmp.a));
		int l=0;
		For(j,0,n-1)
			if (j==n-1||(i&(1<<j)))
				++tmp.a[l+1],l=0;
			else ++l;
		h[i]=g[mp[tmp]];
	}
	n--;
	for (int d=1;d<1<<n;d<<=1)
		for (int i=0;i<1<<n;i+=d<<1)
			for (int j=0;j<d;j++)
				h[i+j+d]-=h[i+j];
	For(i,0,(1<<n)-1)
		printf("%lld ",h[i]);
}
/*
2^nban
n^3 
2^n*((n^3)+) 
*/