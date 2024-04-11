#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	long long int n,k,cnt=0,ans=0,cal;
	scanf("%I64d%I64d",&n,&k);
	cal=(long long int)sqrt(n);
	if(cal*cal==n) cal--;
	for(long long int i=1;i<=cal;i++){
		if(n%i==0)cnt++;
		if(cnt==k){ans=i;break;}
	}
	if(!ans){
		if((cal+1)*(cal+1)==n){
			if(k>cnt*2+1){printf("-1");return 0;}
			else if(k==cnt+1){printf("%I64d",cal+1);return 0;}
			else k=2*cnt+2-k;
		}
		else {
			if(k>cnt*2){printf("-1");return 0;}
			else k=2*cnt+1-k;
		}
		cnt=0;
		for(long long int i=1;i<=cal;i++){
			if(n%i==0)cnt++;
			if(cnt==k){ans=n/i;break;}
		}
	}
	printf("%I64d",ans);
	return 0;	
}