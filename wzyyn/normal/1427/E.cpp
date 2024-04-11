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
struct node{
	ll tp,x,y;
};
vector<node> ans;
void Mul(ll x,ll y){
	ll s=0;
	for (;y;){
		if (y&1)
			ans.PB((node){2,s,x}),s+=x;
		if (y/=2)
			ans.PB((node){2,x,x}),x+=x;
	}
}
void exgcd(ll x,ll y,ll &a,ll &b){
	if (!y){
		a=1; b=0;
		return;
	}
	exgcd(y,x%y,b,a);
	b-=x/y*a;
}
int main(){
	ll x;
	scanf("%lld",&x);
	ans.PB((node){1,x,x});
	ll y=1;
	for (;y*2<=x;y*=2);
	Mul(x,y);
	ll z=x*y;
	ans.PB((node){1,z,x});
	z^=x;
	//cout<<z<<' '<<x<<endl;
	ll a,b;
	exgcd(x,z,a,b); b*=-1;
	for (;a<0||b<0;b+=x,a+=z);//if (a<0) a*=-1,b*=-1; b*=-1;
	if (b%2==1) b+=x,a+=z; 
	Mul(x,a); Mul(z,b); 
	ans.PB((node){1,x*a,z*b}); 
	printf("%d\n",ans.size());
	for (auto i:ans)
		printf("%lld %c %lld\n",i.x,i.tp==1?'^':'+',i.y);
}