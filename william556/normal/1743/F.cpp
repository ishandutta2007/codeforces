// LUOGU_RID: 90774657
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=3e5+5,mod=998244353;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return (long long)a*b%mod;}
struct matrix{
	int a[2][2];
	int* operator [](int x){return a[x];}
}mt[N<<2],m0,m1;
matrix operator * (matrix a,matrix b){
	static matrix c;
	c[0][0]=(1ll*a[0][0]*b[0][0]+1ll*a[0][1]*b[1][0])%mod;
	c[0][1]=(1ll*a[0][0]*b[0][1]+1ll*a[0][1]*b[1][1])%mod;
	c[1][0]=(1ll*a[1][0]*b[0][0]+1ll*a[1][1]*b[1][0])%mod;
	c[1][1]=(1ll*a[1][0]*b[0][1]+1ll*a[1][1]*b[1][1])%mod;
	return c;
}
int n,m;
vector<int> v1[N],v2[N];
void build(int p,int l,int r){
	if(l==r){
		mt[p]=m0;
		return;	
	}
	int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	mt[p]=mt[p<<1]*mt[p<<1|1];
}
void modify(int p,int l,int r,int d,int v){
	if(l==r){
		if(v==1)mt[p]=m1;
		else mt[p]=m0;
		return;	
	}
	int mid=l+r>>1;
	if(d<=mid)modify(p<<1,l,mid,d,v);
	else modify(p<<1|1,mid+1,r,d,v);
	mt[p]=mt[p<<1]*mt[p<<1|1];
}
int main(){
//	freopen("in.txt","r",stdin);
	n=in();
	int l1,r1;
	for(int i=1;i<=n;i++){
		int l=in(),r=in();
		if(i==1)l1=l,r1=r;
		m=max(m,r);
		v1[l].push_back(i);
		v2[r+1].push_back(i);	
	}
	m0[0][0]=3,m0[1][0]=1,m0[1][1]=2;
	m1[0][0]=1,m1[0][1]=2,m1[1][0]=1,m1[1][1]=2;
	build(1,2,n);
	int ans=0;
	for(int i=0;i<=m;i++){
		for(int j:v1[i])if(j>1)modify(1,2,n,j,1);
		for(int j:v2[i])if(j>1)modify(1,2,n,j,0);
		int p=0;
		if(i>=l1&&i<=r1)p=1;
		ans=add(ans,mt[1][p][1]);
	}
	cout<<ans<<endl;
	return 0;
}