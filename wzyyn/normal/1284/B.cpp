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
const int N=1000005;
int n,a[N],S[N],T[N],S1;
int main(){
	int n;
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		For(j,1,x) scanf("%d",&a[j]);
		int fl=0;
		For(j,2,x)
			if (a[j]>a[j-1])
				fl=1;
		if (fl) S1++;
		else{
			S[a[1]]++;
			T[a[x]]++;
		}
	}
	ll ans=0;
	For(i,1,1000000) S[i]+=S[i-1];
	For(i,0,1000000) ans+=1ll*T[i]*(S[1000000]-S[i]);
	//printf("%d\n",ans);
	ans=ans+1ll*n*n-1ll*(n-S1)*(n-S1);
	printf("%lld\n",ans);
	//printf("")
}