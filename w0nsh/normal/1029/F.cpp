#include <bits/stdc++.h>
long long a,b,min=1e18;
std::vector<std::pair<long long,long long> > div_a,div_b,div_s;
int main(){
	std::scanf("%lld%lld",&a,&b);
	for(long long i=1;i*i<=a;++i)if(a%i==0)div_a.push_back({i,a/i});
	for(long long i=1;i*i<=b;++i)if(b%i==0)div_b.push_back({i,b/i});
	for(long long i=1;i*i<=a+b;++i)if((a+b)%i==0)div_s.push_back({i,(a+b)/i});
	for(auto i:div_a)for(auto j:div_s)if(j.first>=i.first&&j.second>=i.second)min=std::min(min,j.first*2+j.second*2);
	for(auto i:div_b)for(auto j:div_s)if(j.first>=i.first&&j.second>=i.second)min=std::min(min,j.first*2+j.second*2);
	std::printf("%lld",min);
	return 0;
}