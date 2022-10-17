#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
double res,a[100500],pre[100500],sb;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=-1e18;
		for(i=1;i<=n;i++){
			scanf("%lf",&a[i]);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			pre[i]=pre[i-1]+a[i];
		}
		sb=0;
		for(i=n;i>1;i--){
			sb+=a[i];
			res=max(res,sb/(n+1-i)+pre[i-1]/(i-1));
		}
		printf("%.20lf\n",res);
	}
}