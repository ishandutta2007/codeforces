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
const int N=500005;
const int mo=998244353;
int t[N*4][2][2];
int n,m;
char s[N];
void pushup(int k){
	memset(t[k],0,sizeof(t[k]));
	For(i,0,1) For(j,0,1)
		t[k][i][j]=(1ll*t[k*2][i][0]*t[k*2+1][0][j]+1ll*t[k*2][i][1]*t[k*2+1][1][j])%mo;
}
void build(int k,int l,int r){
	if (l==r){
		memset(t[k],0,sizeof(t[k]));
		t[k][1][0]=1;
		t[k][0][0]=s[l]+1;
		if (s[l]==1) t[k][0][1]=9-s[l+1];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int p){
	if (l==r){
		memset(t[k],0,sizeof(t[k]));
		t[k][1][0]=1;
		t[k][0][0]=s[l]+1;
		if (s[l]==1) t[k][0][1]=9-s[l+1];
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	pushup(k);
}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	For(i,1,n) s[i]-='0';
	build(1,1,n);
	while (m--){
		int x,y;
		scanf("%d%d",&x,&y);
		s[x]=y;
		if (x!=1) change(1,1,n,x-1);
		change(1,1,n,x);
		printf("%d\n",t[1][0][0]);
	}
}