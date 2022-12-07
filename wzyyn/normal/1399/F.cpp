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
const int N=6005;
int n,q[N],l[N],r[N];
int f[N],g[N];
vector<pii> e[N];
void solve(){
	*q=0;
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d",&l[i],&r[i]);
		l[i]=l[i]*2; r[i]=r[i]*2+1;
	}
	l[++n]=0; r[n]=1e9;
	For(i,1,n) q[++*q]=l[i],q[++*q]=r[i];
	For(i,1,n*2) e[i].resize(0);
	sort(q+1,q+*q+1);
	For(i,1,n){
		l[i]=lower_bound(q+1,q+*q+1,l[i])-q;
		r[i]=lower_bound(q+1,q+*q+1,r[i])-q;
		e[r[i]].PB(pii(l[i],i));
		g[i]=0;
	}
	int ans=0;
	For(i,1,*q){
		sort(e[i].begin(),e[i].end());
		reverse(e[i].begin(),e[i].end());
		for (auto j:e[i]){
			f[j.fi-1]=0;
			For(k,j.fi,i){
				f[k]=f[k-1];
				for (auto l:e[k])
					if (l.fi>=j.fi)
						f[k]=max(f[k],f[l.fi]+g[l.se]);
			}
			g[j.se]=f[i]+1;
			ans=max(ans,f[i]+1);
		}
	}
	cout<<ans-1<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}