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
const int N=1000005;
int k,n,a[N],l[N],r[N],q[N],ans;
int F(int l){
	int pr=5000000/k*k;
	int pl=l+(k-l%k)%k;
	return 1ll*(pr+pl-2*l+2)*(pr/k-pl/k+1)/2%mo;
}
int Func(int vl,int vr){
	int ans=F(0);
	//cout<<ans<<endl;
	ans=(ans+mo-F(vl))%mo;
	//cout<<ans<<endl;
	ans=(ans+mo-F(vr))%mo;
	//cout<<ans<<endl;
	ans=(ans+F(vl+vr))%mo;
	return ans+mo-1;
}
int main(){
	scanf("%d%d",&n,&k); --k;
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) l[i]=0,r[i]=n+1;
	int t=1; q[1]=1;
	For(i,2,n){
		for (;t&&a[q[t]]<=a[i];--t)
			r[q[t]]=i;
		l[i]=q[t]; q[++t]=i;
	}
	For(i,1,n){
		//cout<<l[i]<<' '<<r[i]<<' '<<ans<<endl;
		ans=(ans+1ll*a[i]*Func(i-l[i],r[i]-i))%mo;
	}
	cout<<ans<<endl;
}