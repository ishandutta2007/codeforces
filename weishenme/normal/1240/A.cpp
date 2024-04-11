#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int a[N],b[N],n,k,A,B,x,y,T; 
int cmp(int x,int y){
	return x>y;
}
signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld",&n);
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
		scanf("%lld%lld%lld%lld",&x,&A,&y,&B);
		if (x<y)swap(A,B),swap(x,y); 
		scanf("%lld",&k);
		int cnt1=0,cnt2=0,cnt3=0;;
		for (int i=1;i<=n;i++){
			if (i%A==0&&i%B==0)cnt3++;
			else if (i%A==0)cnt1++;
			else if (i%B==0)cnt2++;
			if (b[cnt3]/100*(x+y)+(b[cnt3+cnt1]-b[cnt3])/100*x+(b[cnt3+cnt1+cnt2]-b[cnt3+cnt1])/100*y>=k){
				printf("%lld\n",i);
				k=-1;
				break;
			}
		}
		if (k!=-1)puts("-1");
	}
}