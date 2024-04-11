#include<bits/stdc++.h>
using namespace std;
int n;
int a[110000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		long long r1=0,sum=0,r2=0,r3=0,ii,aa;
		for(int i=2;i<n;i++){
			if(a[i]&1) r1++;
			if((a[i]>=2)&&(a[i]%2==0)) r2++;
			if((a[i]>=2)&&(a[i]%2==1)) r3++;
			if(a[i]&1){
				ii=i;
				aa=a[i];
			}
			sum+=a[i];
		}
		if(r2||(r1==0)||(r3&&(r1>1))){
			printf("%lld\n",(sum+r1)/2);
			continue;
		}
		if(r3==0){
			printf("-1\n");
			continue;
		}
		if(n==3){
			printf("-1\n");
			continue;
		}
		if(aa<=3){
			printf("-1\n");
			continue;
		}
		printf("%lld\n",(aa+3)/2);
	}
	return 0;
}