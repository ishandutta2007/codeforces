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
const int N=200005;
int n,p[N],q[N];
void solve(){
	*q=0;
	scanf("%d",&n);
	ll res=*q=0; q[++*q]=1;
	For(i,n/2+1,n) q[++*q]=i,res+=1ll*(i-1)*(i-1);
	Rep(i,n/2,1) q[++*q]=i,res+=1ll*(n-i)*(n-i);
	printf("%lld\n",res-1ll*(n-1)*(n-1));
	For(i,1,n) p[q[i]]=q[i+1];
	For(i,1,n) printf("%d ",p[i]); puts("");
	printf("%d\n",n-1);
	For(i,n/2+1,n-1) printf("%d %d\n",i,1);
	Rep(i,n/2,1) printf("%d %d\n",i,n);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}