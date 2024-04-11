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
const int mo=998244353;
const int N=5005;
int n,m,k,ans,f[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	f[1]=1;
	For(i,2,k) Rep(j,i,1)
		f[j]=1ll*j*(f[j-1]+f[j])%mo;
	int cv=1;
	For(i,1,k){
		cv=1ll*cv*(n+1-i)%mo*power(i,mo-2)%mo;
		ans=(ans+1ll*cv*f[i]%mo*power(m,mo-1-i))%mo;
	}
	printf("%d\n",ans); 
}