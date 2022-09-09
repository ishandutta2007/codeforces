#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int a[N],c[N];
map<pair<int,int>,int> qs;
int main(){
	int n;
	scanf("%i",&n);
	ll sum=0;
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),c[i]=0,sum+=a[i];
	int q;
	scanf("%i",&q);
	while(q--){
		int s,t,x;
		scanf("%i %i %i",&s,&t,&x);
		if(qs.count({s,t})){
			c[qs[{s,t}]]--;
			if(c[qs[{s,t}]]<a[qs[{s,t}]])sum++;
			qs.erase({s,t});
		}
		if(x){
			c[x]++;
			if(c[x]<=a[x])sum--;
			qs[{s,t}]=x;
		}
		printf("%lld\n",sum);
	}
	return 0;
}