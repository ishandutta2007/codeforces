#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define rep(i,l,r) for(int i=l;i<=r;i++)
 
int n;
long long a[N], l[N], r[N], s[N], ma, ans;
 
int main(){
	scanf("%d",&n);
	s[1] = l[1] = r[n] = 0;
	rep(i,1,n-1) scanf("%I64d",a+i), s[i+1] = s[i] + (a[i] - 1 | 1);
	rep(i,2,n) l[i] = a[i-1]==1 ? 0 : l[i-1] + (a[i-1] >> 1 << 1);
	for(int i=n-1;i;i--) r[i] = a[i]==1 ? 0 : r[i+1] + (a[i] >> 1 << 1);
	rep(i,1,n){
		ans = max(s[i] + r[i] + ma, ans);
		ma = max(ma, l[i] - s[i]);
	}
	printf("%I64d\n",ans);
}