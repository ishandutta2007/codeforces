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
int a[100005];
int b[100005];
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		For(i,1,n) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		*b=0;
		int l=1,r=n;
		for (;l<=r;){
			if (l<=r) b[++*b]=a[l++];
			if (l<=r) b[++*b]=a[r--];
		}
		Rep(i,*b,1) printf("%d ",b[i]);
		puts("");
	}
}