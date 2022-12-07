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
int n,a[100005],b[100005];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),b[i]=b[i-1]^a[i];
	if (n>=70) return puts("1"),0;
	int ans=1<<30;
	For(i,0,n) For(j,i+1,n) For(k,j+1,n)
		if ((b[j]^b[i])>(b[k]^b[j]))
			ans=min(ans,k-i-2);
	if (ans==1<<30) ans=-1;
	cout<<ans<<endl;
}