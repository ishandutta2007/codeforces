#include <bits/stdc++.h>
#define sq(x) (x)*(x)
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const ll MN = 2002;
pair<ll,ll> p[MN], a, b;
ll N, i, j; long long ans=1LL<<60, tmp;

int main(){
	scanf("%lld%lld%lld%lld%lld",&N,&a.first,&a.second,&b.first,&b.second);
	for(i=1;i<=N;i++)
		scanf("%lld%lld",&p[i].first,&p[i].second);
	sort(p+1,p+N+1,[](pii i,pii j){
		long long d1=sq(i.first-a.first)+sq(i.second-a.second);
		long long d2=sq(j.first-a.first)+sq(j.second-a.second);
		return d1<d2;
	});
	for(i=1;i<=N;i++){
		long long d1=sq(p[i].first-a.first)+sq(p[i].second-a.second);
		tmp = 0;
		for(j=i+1;j<=N;j++){
			long long d2=sq(p[j].first-b.first)+sq(p[j].second-b.second);
			tmp = max(tmp, d2);
		}
		ans = min(ans, d1+tmp);
	}
	tmp = 0;
	for(j=1;j<=N;j++){
		long long d2=sq(p[j].first-b.first)+sq(p[j].second-b.second);
		tmp = max(tmp, d2);
	}
	ans = min(ans, tmp);
	printf("%lld\n",ans);
	return 0;
}