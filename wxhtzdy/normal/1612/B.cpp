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
const int N=101;
int n,a,b,ans[N],cc[N];
void solve(){
	scanf("%d%d%d",&n,&a,&b);
	For(i,1,n) 
		cc[i]=0;
	cc[b]=1;
	ans[1]=a;
	cc[a]=1;
	For(i,2,n/2){
		int v=0;
		For(j,a,n)
			if(!cc[j])
				v=j;
		if (v==0){
			puts("-1");
			return;
		}
		ans[i]=v;
		cc[v]=1;
	}
	ans[n/2+1]=b;
	For(i,n/2+2,n){
		int v=0;
		For(j,1,b)
			if (!cc[j])
				v=j;
		if (v==0){
			puts("-1");
			return;
		}
		ans[i]=v;
		cc[v]=1;
	}
	For(i,1,n)
		printf("%d ",ans[i]); puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}