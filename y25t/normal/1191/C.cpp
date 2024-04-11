#include<cstdio>
#define ll long long
#define N 100005

ll m,n,k,a[N];

ll ans;

int main(){
	scanf("%I64d%I64d%I64d",&m,&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	ll p=0,tmp=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]-tmp<=p){
			cnt++;
			continue;
		}
		ans++;
		tmp+=cnt;
		cnt=1;
		p=((a[i]-tmp-1)/k+1)*k;
	}
	printf("%I64d",ans);
}