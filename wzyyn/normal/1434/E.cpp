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
const int M=505;
int n,T,ans,b[N],c[N];
int f[N],lf[N],fa[N],v[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int fix(int l,int r,int i){
	//cout<<l<<' '<<r<<' '<<i<<endl;
	for (;(l=get(l))<=r;fa[l]=l+1)
		f[l]=max(lf[l],int(upper_bound(v+1,v+n+1,2*v[l]-v[i])-v-1));
}
int calc_SG(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&v[i]);
	if (n==1) return 1;
	int p=0,rem=n;
	For(i,0,n) b[i]=-1; 
	For(i,1,n){
		for (;p+1<i&&v[i]-v[p+1]>=v[n]-v[i];++p);
		f[i]=p;
	}
	For(k,1,500){
		For(i,0,n) lf[i]=f[i],c[i]=0;
		For(i,1,n+1) fa[i]=i,f[i]=i-1;
		int rem=0;
		Rep(i,n,1){
			if (lf[i]<f[i])
				fix(lf[i]+1,f[i],i);
			++c[lf[i]+1];
			--c[f[i]+1];
		}
		bool flag=0;
		For(i,1,n){
			c[i]+=c[i-1];
			if (b[i]==-1&&!c[i]) b[i]=k,--rem;
		}
		if (!rem){
			//cout<<"ANS= "<<k<<endl;
			return k;
		}
	}
}
int main(){
	scanf("%d",&T);
	For(i,1,T) ans^=calc_SG();
	puts(ans?"YES":"NO");
}