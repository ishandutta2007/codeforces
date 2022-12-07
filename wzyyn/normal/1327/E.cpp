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
const int N=(1<<18);
int n,v[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		v[i]=1ll*power(10,n-i+1)%mo;
		v[i]=(v[i]+1ll*(n-i)*9%mo*power(10,n-i))%mo;
	}
	For(i,1,n)
		printf("%d ",(v[i]+mo-v[i+1])%mo);
	//cout<<v[1]<<' '<<v[2]<<endl;
}
/*
ABC 720
ABA 90
AAB/ABB 90

720*3+
*/