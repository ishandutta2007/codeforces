#include <cstdio>
#define max_n 1000000
using namespace std;
int arr[max_n+4];
int main(){
	int*a=arr,*now=a,n,ans=0;
	while(scanf("%1d",++now)==1);
	n=now-a-1;
	int cnt=0,m;
	a[0]=a[1];
	if(a[1]!=a[n]){
		cnt=1;
		for(int i=n; a[i]!=a[i-1]; --i,++cnt);
		if(cnt==n){
			printf("%d\n",n>>1);
			return 0;
		}
		m=n-cnt;
	}
	else
		m=n;
	a[0]=a[n],a[n+1]=a[1];
	for(int i=0; ++i<=m; )
		if(a[i]!=a[i+1])
			++cnt;
		else{
			if(cnt){
//			cnt>2&&printf("%d %d\n",i,cnt);
				ans+=cnt-1>>1;
				cnt=0;
			}
		}
	if(a[n]==a[1])
		while(a[--n]==a[1]);
//	printf("%d %d\n",n,ans);
	for(int i=0; ++i<=n; ans+=bool(a[i]!=a[i+1]&&a[i]==a[i-1]));
	printf("%d\n",ans);
	return 0;
}