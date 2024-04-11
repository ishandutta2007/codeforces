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
int n,k,a[N];
bool check(int v){
	int s=0;
	For(i,1,n)
		if (s%2==0) s++;
		else if (a[i]<=v) s++;
	if (s>=k) return 1;
	s=0;
	For(i,1,n)
		if (s%2==1) s++;
		else if (a[i]<=v) s++;
	if (s>=k) return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	int l=0,r=1e9,ans=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}