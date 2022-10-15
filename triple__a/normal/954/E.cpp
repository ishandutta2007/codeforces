#include "bits/stdc++.h"

using namespace std;

const int maxn=200007;

struct ct{
	friend bool operator<(ct x,ct y){
		return x.t<y.t;
	}
	long long a,t;
}p[maxn];

long long n,t;

int main(){
	long long ans=0;
	long long sum_t=0;
	scanf("%lld%lld",&n,&t);
	for (int i=0;i<n;++i){
		scanf("%lld",&p[i].a);
	}
	for (int i=0;i<n;++i){
		scanf("%lld",&p[i].t);
	}
	sort(p,p+n);
	for (int i=0;i<n;++i){
		sum_t+=(long long)p[i].a*p[i].t;
		ans+=p[i].a;
	}
	if (sum_t==ans*t){
		printf("%lld",ans);
		return 0;
	}
	if (sum_t>ans*t){
		int k=n-1;
		while(k>-1){//(sum_t-x*pt)/(ans-x)=t;
			if (sum_t-(long long)p[k].a*p[k].t<=(ans-p[k].a)*t){
				printf("%.10lf\n",1.0*((long long)p[k].t*ans-sum_t)/(p[k].t-t));
				return 0;
			}
			sum_t-=(long long)p[k].a*p[k].t;
			ans-=p[k].a;
			k--;
		}
		printf("0");
		return 0;
	}
	else{
		int k=0;
		while (k<n){
//			cout<<ans<<" "<<sum_t<<" "<<p[k].t<<" "<<p[k].a<<endl;
			if (sum_t-p[k].a*p[k].t>=(ans-p[k].a)*t){
				printf("%.10lf\n",1.0*((long long)p[k].t*ans-sum_t)/(p[k].t-t));
				return 0;
			}
			sum_t-=(long long)p[k].a*p[k].t;
			ans-=p[k].a;
			k++;
		}
		printf("0");
		return 0;
	}
	return 0;
}