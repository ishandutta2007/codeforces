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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int N=1000005;
int n,m,a[N];
ll b[N],ans,S;
void check(ll v){
	//printf("%lld\n",v);
	For(i,1,n) b[i]=a[i]%v;
	int l=1;
	ll sum=0,S=0;
	for (int r=1;r<=n;++r){
		sum+=b[r];
		if (sum>=v){
			//printf("%d %d\n",l,r);
			int pos=l;
			ll tmp=0;
			for (;tmp*2<v;)
				tmp+=b[pos],++pos;
			--pos;
			for (int i=l;i<r;i++)
				S+=1ll*b[i]*abs(i-pos);
			sum-=b[r];
			S+=1ll*(v-sum)*abs(r-pos);
			b[r]-=(v-sum);
			l=r; sum=b[r];
		}
	}
	ans=min(ans,S);
}
int main(){
	ans=1ll<<60;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),S+=a[i];
	for (int i=2;1ll*i*i<=S;++i)
		if (S%i==0){
			check(i);
			for (;S%i==0;S/=i);
		}
	if (S!=1)
		check(S);
	if (ans==(1ll<<60)) puts("-1");
	else printf("%lld\n",ans);
}