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
const int N=500005;
int n,ans,a[N],f[N],g[N],s[N],l[N],r[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		if (!l[a[i]]) l[a[i]]=i;
		r[a[i]]=i;
	}
	Rep(i,n,1) f[i]=max(f[i+1],++s[a[i]]);
	For(i,1,n){
		g[i]=max(g[i],g[i-1]);
		if (l[a[i]]==i) g[r[a[i]]+1]=max(g[r[a[i]]+1],g[i]+s[a[i]]);
	}
	For(i,1,n+1) ans=max(ans,f[i]+g[i]);//cout<<f[i]<<' '<<g[i]<<endl;
	cout<<n-ans<<endl;
}