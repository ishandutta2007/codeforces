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
int n,q[1005],x;
void solve(){
	bool f1=0,f2=0;
	*q=0;
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&x);
		if (x==0){
			if (f1) q[++*q]=0,q[++*q]=0,f1=f2=0;
			else f1=1;
		}
		else{
			if (f2) q[++*q]=1,q[++*q]=1,f1=f2=0;
			else f2=1;
		}
	}
	if (f1) q[++*q]=0;
	printf("%d\n",*q);
	For(i,1,*q) printf("%d ",q[i]); puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}