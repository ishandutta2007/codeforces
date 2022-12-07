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
const int N=2000005;
int n,mx,q[N],cnt[N];
void solve(){
	scanf("%d",&n);
	mx=n; *q=0;
	For(i,1,n) cnt[i]=0;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		++cnt[x];
	}
	For(i,1,n)
		if (cnt[i]){
			mx=min(mx,cnt[i]+1);
			q[++*q]=i;
		}
	ll ans=n;
	For(i,2,mx){
		ll sum=0;
		For(j,1,*q){
			int x=cnt[q[j]];
			if (x%(i-1)>x/(i-1))
				sum+=1<<30;
			else{
				int v1=x%(i-1),v2=x/(i-1);
				int rnd=(v2%i<v1?v2/i-1:v2/i);
				sum+=rnd*(i-1)+(v2-rnd*i);
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}