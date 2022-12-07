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
int a[1005];
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		For(i,1,n) scanf("%d",&a[i]);
		int l=1,r=n,s1=0,s2=0,s3=0,pre=0;
		for (;;){
			int s=0; ++s3;
			for (;l<=r&&s<=pre;s+=a[l],s1+=a[l],l++);
			if (l>r) break;
			pre=s; ++s3; s=0;
			for (;l<=r&&s<=pre;s+=a[r],s2+=a[r],r--);
			if (l>r) break;
			pre=s;
		}
		printf("%d %d %d\n",s3,s1,s2);
	} 
}