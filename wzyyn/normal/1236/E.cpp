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
const int N=100005;
int n,m;
int a[N],l[N*3],r[N*3];
int main(){
	scanf("%d%d",&n,&m);
	if (n==1) return puts("0"),0;
	For(i,1,m) scanf("%d",&a[i]);
	Rep(i,m,1){
		l[a[i]+i+m]=l[a[i]+i+1+m]+1;
		r[a[i]-i+m]=r[a[i]-i-1+m]+1;
	}
	ll ans=0;
	For(i,1,n){
		ans+=min(i+(m+1)-r[i+m],n);
		ans-=max(i-(m+1)+l[i+m],1);
		ans++;
	}
	cout<<ans<<endl;
		 
}