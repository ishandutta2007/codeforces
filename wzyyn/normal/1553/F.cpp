#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
 
const int B=768;
const int N=300005;
ll S2[N+B],S1[B];
ll S4[N+B],S3[B];
int n,bel[N];
int main(){
	scanf("%d",&n);
	ll ans=0,sum=0;
	for (int i=1;i<N;i++) bel[i]=i/B;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ans+=1ll*(i-1)*x+sum;
		ll pre=0;
		for (int j=0;j<bel[x];j++)
			ans-=S3[j]*x;
		for (int j=bel[x]*B;j<=x;j++)
			ans-=S4[j]*x;
		for (int l=1,r;l<=x;l=r+1){
			r=x/(x/l);
			ll now=S1[bel[r]]+S2[r];
			S3[bel[l]]+=x/l; S4[l]+=x/l;
			S3[bel[r+1]]-=x/l; S4[r+1]-=x/l;
			ans-=(x/l)*(now-pre);
			pre=now;
		}
		printf("%lld ",ans);
		for (int j=bel[x]+1;j<=bel[N-1];j++)
			S1[j]+=x;
		for (int j=x;j<(bel[x]+1)*B;j++)
			S2[j]+=x;
		sum+=x;
	}
}