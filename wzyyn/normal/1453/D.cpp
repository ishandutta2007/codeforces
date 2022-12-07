#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;
ll f[65];
int a[2505],q[1000];
bool F(ll x){
	return x%2==0;
}
void solve(){
	ll x;
	scanf("%lld",&x);
	if (x%2==1) return puts("-1"),void(0);
	*q=0; x-=2;
	q[++*q]=1;
	Rep(i,60,1)
		for (;x>=f[i]&&F(x-f[i]);)
			x-=f[i],q[++*q]=i;
	memset(a,0,sizeof(a));
	int S=0;
	For(i,1,*q) a[S+=q[i]]=1;
	printf("%d\n",S);
	For(i,1,S) printf("%d ",a[i]);
	puts("");
}
int main(){
	For(i,1,60){
		For(j,1,i) f[i]+=(1ll<<(i-j))*(j); f[i]+=i;
	}
	int T;
	scanf("%d",&T);
	while (T--) solve();
	//scanf("%d",&n);
}
/*
f[1]=2
f[2]=4
f[3]=
4*1+2*2+1*3+=8*x
x=13
*/