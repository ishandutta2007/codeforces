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
const int N=100000;
struct Int{
	ull a[5];
	Int(){
		memset(a,0,sizeof(a));
	}
	Int operator +(const Int &b)const{
		Int ans;
		For(i,0,4)
			ans.a[i]=a[i]+b.a[i];
		return ans;
	}
	Int operator -(const Int &b)const{
		Int ans;
		For(i,0,4)
			ans.a[i]=a[i]-b.a[i];
		return ans;
	}
	Int operator *(const Int &b)const{
		Int ans;
		For(i,0,4) For(j,0,4)
			ans.a[(i+j)%5]+=a[i]*b.a[j];
		return ans;
	}
	Int shift(int x){
		Int ans;
		For(i,0,4)
			ans.a[(i+x)%5]=a[i];
		return ans;
	}
}a[N],tmp[10];
int n;
Int power(Int x,int y){
	Int s; s.a[0]=1;
	for (;y;y/=2,x=x*x)
		if (y&1) s=s*x;
	return s;
}
ull power(ull x,ll y){
	ull s=1;
	for (;y;y/=2,x*=x)
		if (y&1) s*=x;
	return s;	
}
void FWT(Int *a,int n,int f){
	if (n==1) return;
	For(i,0,9) FWT(a+n/10*i,n/10,f);
	For(i,0,n/10-1){
		memset(tmp,0,sizeof(tmp));
		For(j,0,9) For(k,0,9){
			int b=(10+j*k*f%10)%10;
			if (b&1) tmp[j]=tmp[j]-a[n/10*k+i].shift((b+5)/2);
			else tmp[j]=tmp[j]+a[n/10*k+i].shift(b/2);
		}
		For(j,0,9)
			a[n/10*j+i]=tmp[j];
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		++a[x].a[0];
	}
	FWT(a,N,1);
	//For(i,0,N-1) printf("%d\n",a[i].a[0]);
	For(i,0,N-1) a[i]=power(a[i],n);
	FWT(a,N,-1);
	ull Inv=power(3125,(1ull<<63)-1);
	For(i,0,n-1){
		ull ans=(a[i].a[0]-a[i].a[1])/32;
		ans=(ans*Inv)&((1ull<<58)-1);
		printf("%llu\n",ans);
	}
}