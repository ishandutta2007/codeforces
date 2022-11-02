#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll f[100009][2],a[100009],num[100009];
int main(){
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),num[a[i]]++;
	sort(a+1,a+n+1);
	int len=unique(a+1,a+n+1)-a-1;
	memset(f,0,sizeof(f));
	f[1][0]=0,f[1][1]=num[a[1]]*a[1];
	for(int i=2;i<=len;i++){
		if(a[i]==a[i-1]+1) f[i][1]=f[i-1][0]+num[a[i]]*a[i];
		else f[i][1]=max(f[i-1][0],f[i-1][1])+num[a[i]]*a[i];
		f[i][0]=max(f[i-1][1],f[i-1][0]);
	}
	printf("%lld\n",max(f[len][0],f[len][1]));
	return 0;
}