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
const int N=400005;
int n,k,a[N],S[N];
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,2*k) S[i]=0;
	For(i,1,n/2){
		int x=a[i],y=a[n-i+1];
		S[2]+=2; S[min(x,y)+1]--; S[x+y]--;
		S[x+y+1]++; S[max(x,y)+k+1]++;
	}
	For(i,2,2*k) S[i]+=S[i-1];
	int ans=1<<30;
	For(i,2,2*k) ans=min(ans,S[i]);
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}