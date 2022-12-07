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
const int N=500005;
int a[N],id[N],n,ans;
bool cmp(int x,int y){
	return a[x]<a[y];
}
struct Tarr{
	ll a[N];
	void change(int k,int v){
		for (;k<=n;k+=k&(-k)) a[k]+=v;
	}
	ll ask(int k){
		ll ans=0;
		for (;k;k-=k&(-k)) ans+=a[k];
		return ans;
	}
	ll ask(int l,int r){
		return ask(r)-ask(l-1);
	}
}T1,T2;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	For(i,1,n){
		int x=id[i];
		T1.change(x,1);
		T2.change(x,x);
		ll S=T2.ask(1,x);
		ans=(ans+S%mo*a[x]%mo*(n-x+1))%mo;
		S=T1.ask(x+1,n)*(n+1)-T2.ask(x+1,n);
		ans=(ans+S%mo*a[x]%mo*x)%mo;
	}
	printf("%d\n",ans);
}