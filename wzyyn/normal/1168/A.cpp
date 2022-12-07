#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,m,a[300005];
bool check(int v){
	int vnow=0;
	For(i,1,n){
		int vl=a[i],vr=a[i]+v;
		for (;vnow<m&&(vnow<vl||vnow>vr)&&(vnow+m<vl||vnow+m>vr);++vnow);
		if (vnow>=m) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	int l=0,r=m,ans;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}