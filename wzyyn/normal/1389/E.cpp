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

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
ll F(int a,int b){
	//cout<<"A "<<a<<' '<<b<<endl;
	a=min(a,b);
	return 1ll*a*(a-1)/2;
}
void solve(){
	int a,b,c,cc;
	scanf("%d%d%d",&a,&b,&c);
	cc=c/gcd(b-1,c);
	ll ans=0;
	if (a%cc<b%cc){
		ans+=1ll*(a%cc)*F(a/cc+1,b/cc+1);
		ans+=1ll*(b%cc-a%cc)*F(a/cc,b/cc+1);
		ans+=1ll*(cc-b%cc)*F(a/cc,b/cc);
	}
	else{
		ans+=1ll*(b%cc)*F(a/cc+1,b/cc+1);
		ans+=1ll*(a%cc-b%cc)*F(a/cc+1,b/cc);
		ans+=1ll*(cc-a%cc)*F(a/cc,b/cc);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
(xm+y)=(ym+x)%w
x(m-1)=y(m-1)%w
*/