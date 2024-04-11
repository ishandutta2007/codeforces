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

int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int n,k;
		scanf("%d%d",&n,&k);
		if (n%2==k%2&&n>=k){
			puts("YES");
			For(i,1,k) printf("%d ",i==k?n-k+1:1);
			puts(""); 
		}
		else if (n%2==0&&n>=2*k){
			puts("YES");
			For(i,1,k) printf("%d ",i==k?n-2*k+2:2);
			puts(""); 
		}
		else puts("NO");
	}
}