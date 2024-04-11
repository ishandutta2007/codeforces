#include "bits/stdc++.h"
using namespace std;

const int maxn=27;
long long s[maxn],sc=0,tp[maxn];
int main(){
	for (int i=0;i<14;++i){
		scanf("%lld",&s[i]);
	}
	for (int i=0;i<14;++i){
		for (int j=0;j<14;++j){
			tp[j]=s[j];
		}
		long long cb=tp[i];
		tp[i]=0;
		for (int j=0;j<14;++j){
			tp[j]+=cb/14+((j-i+13)%14<cb%14);
		}
		long long sum=0;
		for (int j=0;j<14;++j){
			if (tp[j]%2==0){
				sum+=tp[j];
			}
		}
		sc=max(sc,sum);
	}
	printf("%lld\n",sc);
	return 0;
}