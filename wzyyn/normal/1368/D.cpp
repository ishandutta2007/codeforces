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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=1<<21;
int n,p[N],a[N];
int main(){
	scanf("%d",&n);
	For(i,0,30) p[i]=n;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		For(j,0,20)
			if (x&(1<<j)){
				a[p[j]]+=1<<j;
				--p[j];
			}
	}
	ll ans=0;
	For(i,1,n) ans+=1ll*a[i]*a[i];
	cout<<ans<<endl;
}