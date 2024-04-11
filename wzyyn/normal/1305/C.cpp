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
const int N=200005;
int n,m,x,ans;
int a[N],s[N];
ll t[N];
int power(int x,ll y){
	int s=1;
	for (;y;y/=2,x=x*x%m)
		if (y&1) s=s*x%m;
	return s;
}
int main(){
	ans=1;
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	For(i,1,n){
		For(j,0,m-1) t[(a[i]+m-j)%m]+=s[j];
		++s[a[i]%m];
	}
	int ans=1;
	For(i,0,m-1)
		ans=1ll*ans*power(i,t[i])%m;
	printf("%d\n",ans);
}