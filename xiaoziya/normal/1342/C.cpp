#include<bits/stdc++.h>
using namespace std;
const int maxn=40005;
int a,b,q,T;
int suf[maxn],pre[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&q);
		int sum=0;
		for(int i=0;i<a*b;i++){
			if((i%a)%b!=(i%b)%a)
				sum++;
			pre[i]=sum;
		}
		sum=0;
		for(int i=a*b-1;i>=0;i--){
			if((i%a)%b!=(i%b)%a)
				sum++;
			suf[i]=sum;
		}
		while(q--){
			long long l,r;
			scanf("%lld%lld",&l,&r);
			if(l/(a*b)==r/(a*b)){
				l%=(a*b),r%=(a*b);
				printf("%lld\n",pre[r]-(l==0? 0:pre[l-1]));
			}
			else{
				long long s=l/(a*b),t=r/(a*b);
				l%=(a*b),r%=(a*b);
				printf("%lld\n",(t-s-1)*sum+suf[l]+pre[r]);
			}
		}
		for(int i=0;i<a*b;i++)
			pre[i]=suf[i]=0;
	}
	return 0;
}