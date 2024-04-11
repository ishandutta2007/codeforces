#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
#define ll long long
using namespace std;

const int N=1000005;
int n,m;
int a[N],b[N],v[N];
ll D,q[N],K;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void exgcd(int x,int y,int &a,int &b){
	if (!y){
		a=1; b=0;
		return;
	}
	exgcd(y,x%y,b,a);
	b-=x/y*a;
}

int Inv(int x,int y){
	int a,b;
	exgcd(x,y,a,b);
	return (a%y+y)%y;
}
void F(int x,int y){
	if (x%D!=y%D) return;
	int p=x%D; x/=D; y/=D;
	int v1=n/D,v2=m/D;
	q[++*q]=(1ll*y*v1*Inv(v1,v2)+1ll*x*v2*Inv(v2,v1))%(1ll*v1*v2)*D+p;
	if (q[*q]==0) q[*q]=1ll*v1*v2*D;
	//cout<<q[*q]<<endl;
}
int main(){
	scanf("%d%d%lld",&n,&m,&K); D=gcd(n,m);
	For(i,1,n) scanf("%d",&a[i]),v[a[i]]=i;
	For(i,1,m) scanf("%d",&b[i]);
	For(i,1,m) if (v[b[i]]) F(v[b[i]],i);
	ll v=1ll*n*m/D;
	ll l=0,r=1ll<<62,ans=-1;
	while (l<=r){
		ll mid=(l+r)/2,S=mid;
		For(i,1,*q) S-=mid/v+(mid%v>=q[i]);
		if (S>=K) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}