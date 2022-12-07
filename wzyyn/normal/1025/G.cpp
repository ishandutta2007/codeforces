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
const int mo=1000000007;
int n,a[505],S[505];
int F(int x){
	int s=1;
	For(i,1,x) s=2ll*s%mo;
	return s-1;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) ++S[max(a[i],0)];
	int ans=F(n-1);
	For(i,1,n) if (a[i]==-1) ans=(ans+mo-F(S[i]))%mo;
	printf("%d\n",ans);
}
/*
F(p)+F(q)
1/2(F(p+1)+F(q+1))
F(0)=0
F(1)=1
 
*/