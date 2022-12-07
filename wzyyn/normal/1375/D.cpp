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
const int N=1505;
int n,a[N],vis[N],q[N*5];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	*q=0;
	for (;;){
		bool flag=0;
		For(i,1,n) flag|=(a[i]!=i-1);
		if (!flag) break;
		For(i,0,n) vis[i]=0;
		For(i,1,n) vis[a[i]]=1;
		int mex=0;
		for (;vis[mex];++mex);
		if (mex==n){
			int p=0;
			For(i,1,n) if (a[i]!=i-1) p=i;
			q[++*q]=p; a[p]=mex;
		}
		else
			q[++*q]=mex+1,a[mex+1]=mex;
	}
	For(i,0,*q)
		printf("%d%c",q[i],i==0||i==*q?'\n':' ');
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}