#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int mo=1000000007;
const int N=200005;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int n,ans,l[N],r[N];
int v[N],pos[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&l[i]);
	For(i,1,n) scanf("%d",&r[i]);
	For(i,1,n) v[i]=power(r[i]-l[i]+1,mo-2);
	int ans=1ll*n*n%mo,S=0;
	For(i,2,n){
		int len=max(0,min(r[i],r[i-1])-max(l[i],l[i-1])+1);
		pos[i]=1ll*v[i]*v[i-1]%mo*len%mo;
		S=(S+pos[i])%mo;
		ans=(ans+mo-2ll*pos[i]*n%mo)%mo;
	}
	For(i,2,n){
		ans=(ans+pos[i])%mo;
		int SS=(S+mo-pos[i])%mo;
		if (i!=2) SS=(SS+mo-pos[i-1])%mo;
		if (i!=n) SS=(SS+mo-pos[i+1])%mo;
		ans=(ans+1ll*pos[i]*SS)%mo;
		if (i!=2){
			int len=max(0,min(r[i-2],min(r[i],r[i-1]))-max(l[i-2],max(l[i-1],l[i]))+1);
			ans=(ans+1ll*v[i]*v[i-1]%mo*v[i-2]%mo*len)%mo;
		}	
		if (i!=n){
			int len=max(0,min(r[i+1],min(r[i],r[i-1]))-max(l[i+1],max(l[i-1],l[i]))+1);
			ans=(ans+1ll*v[i]*v[i-1]%mo*v[i+1]%mo*len)%mo;
		}
	}
	printf("%d",ans);
}