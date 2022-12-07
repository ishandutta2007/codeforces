#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=300005;
int f[N],g[N],a[N],n;
char ans[N];
struct Tree{
	int nn,t[N*4];
	void build(int n){
		nn=1;
		for (;nn<=n+2;nn<<=1);
		For(i,0,2*nn-1) t[i]=-(1<<30);
	}
	void change(int x,int v){
		for (x+=nn;x;x>>=1) t[x]=max(t[x],v);
	}
	int ask(int l,int r){
		int ans=-(1<<30);
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=max(ans,t[l^1]);
			if (r&1)	ans=max(ans,t[r^1]);
		}
		return ans;
	}
}T1,T2;
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	T1.build(n+2);
	T2.build(n+2);
	For(i,1,n)
		T2.change(i,i+a[i]);
	T1.change(0+1,-0);
	For(i,1,n+1) f[i]=-(1<<30)+5;
	f[0]=0;
	For(i,1,n){
		if (f[i-1]>=i){
			int key=max(f[i-1],i+a[i]);
			if (key>f[i]) f[i]=key,g[i]=-1;
		}//covered
		int p=-T1.ask(max(0,i-a[i]-1)+1,n+2);
		//cout<<p<<endl;
		if (p<i){
			int key=(p==i-1?i-1:T2.ask(p+1,i-1));
			if (key>f[i]) f[i]=key,g[i]=p;
		}
		if (f[i]>=0)
			T1.change(f[i]+1,-i);
		//cout<<i<<' '<<f[i]<<' '<<p<<' '<<g[i]<<endl;
		if (f[i]>=n){
			For(j,1,i) ans[j]='L';
			For(j,i+1,n) ans[j]='R';
			ans[n+1]=0;
			int p=i;
			for (;p!=0;){
				if (g[p]==-1){
					ans[p]='R';
					--p;
				}
				else{
					For(j,g[p]+1,p-1) ans[j]='R';
					p=g[p];
				}
			}
			printf("YES\n%s\n",ans+1);
			return;
		}
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}