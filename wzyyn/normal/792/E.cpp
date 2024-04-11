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
int n,a[505];
ll ans;
void check(int x){
	ll sum=0;
	For(i,1,n){
		int s1=(x-a[i]%x)%x;
		if (1ll*s1*(x-1)>a[i]) return;
		sum+=s1+(a[i]-1ll*s1*(x-1))/x;
	}
	ans=min(ans,sum);
}
int main(){
	scanf("%d",&n);
	ans=1ll<<60;
	For(i,1,n) scanf("%d",&a[i]);
	for (int i=1;i*i<=a[1];i++){
		check(i);
		check(i+1);
		check(a[1]/i);
		check(a[1]/i+1);
	}
	cout<<ans<<endl;
}