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
const int B=1500;
int n,Q,l,r,t,top;
int q[N],a[N],b[N];
int tp[N],x[N],y[N];
int cnt[N],sum[N];
int op[N],ans[N];
bool cmp(int a,int b){
	if (a/B!=b/B) return a<b;
	if (x[a]/B!=x[b]/B) return x[a]<x[b];
	return y[a]<y[b];
}
void flip(int x){
	if (tp[x]==1) return;
	int p=::x[x],c=a[p],nc=::y[x]-c; a[p]=nc;
	if (p<l||p>r) return;
	//cout<<p<<' '<<c<<' '<<nc<<' '<<cnt[c]<<' '<<cnt[nc]<<endl;
	--sum[cnt[c]]; --cnt[c]; ++sum[cnt[c]];
	--sum[cnt[nc]]; ++cnt[nc]; ++sum[cnt[nc]];
}
void add(int x,int v){
	--sum[cnt[x]];
	cnt[x]+=v;
	++sum[cnt[x]];
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) q[++*q]=a[i];
	For(i,1,Q) scanf("%d%d%d",&tp[i],&x[i],&y[i]);
	For(i,1,Q) if (tp[i]==2) q[++*q]=y[i];
	sort(q+1,q+*q+1);
	For(i,1,n) a[i]=b[i]=lower_bound(q+1,q+*q+1,a[i])-q;
	For(i,1,Q) if (tp[i]==2){
		y[i]=lower_bound(q+1,q+*q+1,y[i])-q;
		int tmp=y[i]; y[i]+=b[x[i]]; b[x[i]]=tmp;
	}
	l=1,r=0,t=0,top=0;
	For(i,1,Q) if (tp[i]==1) op[++top]=i;
	sort(op+1,op+top+1,cmp);
	For(i,1,top){
		int T=op[i],L=x[T],R=y[T];
		for (;t<T;flip(++t));
		for (;t>T;flip(t--));
		for (;l>L;add(a[--l],1));
		for (;r<R;add(a[++r],1));
		for (;l<L;add(a[l++],-1));
		for (;r>R;add(a[r--],-1));
		int p=1;
		for (;sum[p];++p);
		ans[T]=p;
		//cout<<T<<' '<<L<<' '' '<<sum[1]<<' '<<sum[2]<<' '<<sum[3]<<endl; 
	}
	For(i,1,Q)
		if (tp[i]==1)
			printf("%d\n",ans[i]);
}