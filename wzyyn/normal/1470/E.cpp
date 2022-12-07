#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=30005;
const int M=300005;
ll f[N][5];
int n,C,Q,a[N],ans[M];

struct node{
	ll rk;
	int p,id;
};
vector<node> op[N][5];
void init(){
	f[0][0]=1;
	f[1][0]=1;
	For(i,2,N-1){
		f[i][0]=1;
		f[i][1]=f[i-1][0]+f[i-1][1];
		f[i][2]=f[i-1][1]+f[i-1][2];
		f[i][3]=f[i-1][2]+f[i-1][3];
		f[i][4]=f[i-1][3]+f[i-1][4];
	}
	For(i,0,N-1) For(j,1,4)
		f[i][j]+=f[i][j-1];
}

pii q[N*5];
int top,id[N*5];
ll t[N*5];
bool cmp(pii x,pii y){
	if (x.fi<y.fi) return a[x.se]<a[x.fi];
	if (x.fi>y.fi) return a[y.fi]<a[y.se];
	return a[x.se]<a[y.se];
}
bool cmp2(int x,int y){
	return cmp(q[x],q[y]);
}
int Loc(int x){
	return lower_bound(id+1,id+top+1,x,cmp2)-id;
}
void change(int x,ll v){
	for (;x<=top;x+=x&(-x)) t[x]+=v;
}
int find(ll v){
	int p=0,d=1;
	for (;(d<<1)<=top;d<<=1);
	for (;d;d>>=1)
		if (p+d<=top&&v>t[p+d])
			p+=d,v-=t[p];
	return p+1;
}
ll ask(int x){
	ll s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
void solve(){
	scanf("%d%d%d",&n,&C,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) For(j,0,4) op[i][j].resize(0);
	For(i,1,Q){
		int x; ll rk;
		scanf("%d%lld",&x,&rk);
		if (rk>f[n][C]) ans[i]=-1;
		else op[1][C].PB((node){rk,x,i});
	}
	Rep(c,C,1){
		top=0;
		For(i,1,n) For(j,1,c) if (i+j<=n)
			q[++top]=pii(i,i+j);
		q[++top]=pii(n,n);
		For(i,1,top) id[i]=i,t[i]=0;
		sort(id+1,id+top+1,cmp2);
		int p=top;
		change(Loc(p--),1);
		Rep(i,n,1){
			Rep(j,c,1) if (i+j<=n)
				change(Loc(p--),f[n-(i+j)][c-j]);
			for (auto j:op[i][c]){
				assert(j.rk<=ask(top));
				int p=find(j.rk);
				pii range=q[id[p]];
				//cout<<"INFO "<<i<<' '<<c<<' '<<range.fi<<' '<<range.se<<' '<<j.id<<' '<<p<<endl;
				if (j.p<range.fi) ans[j.id]=a[j.p];
				else if (j.p<=range.se) ans[j.id]=a[range.fi+range.se-j.p];
				else{
					int rem=c-(range.se-range.fi);
					ll nrk=j.rk-ask(p-1);
					op[range.se+1][rem].PB((node){nrk,j.p,j.id});
				}
			}
		}
	}
	For(i,1,n)
		for (auto j:op[i][0]){
			assert(j.rk==1);
			ans[j.id]=a[j.p];
		}
	For(i,1,Q)
		printf("%d\n",ans[i]);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}