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
const int N=500005;
int n,m,x,a[N];
void Axiba1(){
	ll s=0;
	For(i,1,n) s+=a[i];
	printf("%d\n",s>0?n:-1);
}
void Axiba2(){
	ll S=0;
	For(i,1,n) S+=a[i];
	ll v=S;
	For(i,1,m+1){
		if (v>0){
			printf("%d\n",n-i+1);
			return;
		}
		S-=a[i];
		v=min(S,v-a[n]);
	}
	puts("-1");
}
int main(){
	scanf("%d",&n); m=(n+1)/2;
	For(i,1,m) scanf("%d",&a[i]);
	scanf("%d",&x);
	For(i,m+1,n) a[i]=x;
	if (x>=0) Axiba1();
	else Axiba2();
}