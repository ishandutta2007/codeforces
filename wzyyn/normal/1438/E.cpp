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
int n,ans,a[N],b[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) For(j,0,29) if (a[i]>=(1<<j)) b[i]=j;
	For(i,1,n){
		int S=0;
		For(j,i+1,n-1){
			S+=a[j];
			if (S>=(2<<b[i])) break;
			if (S==(a[i]^a[j+1])&&b[i]>=b[j+1]) ++ans;
		}
	}
	Rep(i,n,1){
		int S=0;
		Rep(j,i-1,2){
			S+=a[j];
			if (S>=(2<<b[i])) break;
			if (S==(a[i]^a[j-1])&&b[i]>b[j-1]) ++ans;
		}
	}
	cout<<ans<<endl;
}