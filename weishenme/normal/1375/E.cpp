#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
int a[N],n,b[N];
int cmp(int x,int y){
	return a[x]>a[y]||(a[x]==a[y]&&x>y);
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]=i+a[i]*(n+1);
	int cnt=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)cnt+=a[i]>a[j];
	printf("%lld\n",cnt);
	for (int i=1;i<=n;i++){
		int tot=0;
		for (int j=i;j<=n;j++)
			if (a[j]<a[i])b[++tot]=j;
		sort(b+1,b+tot+1,cmp);
		for (int j=1;j<=tot;j++){
			swap(a[i],a[b[j]]);
			printf("%lld %lld\n",i,b[j]);
		}
	}
}