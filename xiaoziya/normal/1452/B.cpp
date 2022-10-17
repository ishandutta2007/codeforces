#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		long long sum=0;
		int mx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum+=a[i],mx=max(mx,a[i]);
		printf("%lld\n",max(0ll+((n-1)-sum%(n-1))%(n-1),1ll*(n-1)*mx-sum));
	}
	return 0;
}