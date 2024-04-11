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
const int N=1000555;
int n,ans;
int fl[N],q[N];
ll a[N];
void init(){
	For(i,2,(N-1)) if (!fl[i])
		For(j,2,(N-1)/i) fl[i*j]=1;
	For(i,2,(N-1)/1) if (!fl[i]) q[++*q]=i;
}
int rnd(){
	int x=0;
	For(i,1,9)
		x=x*10+rand()%10;
	return x;
}
void tryBtry(ll x){
	ll val=0;
	For(i,1,n)
		if (a[i]<=x) val+=x-a[i];
		else val+=min(a[i]%x,x-a[i]%x);
	//cout<<x<<' '<<val<<endl;
	if (val<ans) ans=val;
}
void tryAtry(ll x){
	for (int i=1;1ll*q[i]*q[i]<=x;++i)
		if (x%q[i]==0){
			tryBtry(q[i]);
			for (;x%q[i]==0;x/=q[i]);
		}
	if (x>1)
		tryBtry(x);
}
int main(){
	srand(time(NULL));
	init();
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	ans=n;
	For(T,1,25){
		int id=rnd()%n+1;
		tryAtry(a[id]-1);
		tryAtry(a[id]);
		tryAtry(a[id]+1);
	}
	printf("%d\n",ans);
}
/*
n 
*/