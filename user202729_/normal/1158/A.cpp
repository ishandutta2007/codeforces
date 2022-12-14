#include<iostream>
#include<array>
#include<climits>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n_b,n_g;std::cin>>n_b>>n_g;

	std::array<int,2> max_b{{-1,-1}}; // max_b[0] > max_b[1]
	int64_t sum_b=0;
	for(int _=n_b;_--;){
		int x;std::cin>>x;
		sum_b+=x;
		max_b[1]=std::max(max_b[1],x);
		if(max_b[1]>max_b[0])
			std::swap(max_b[0],max_b[1]);
	}

	int64_t sum_g=0;
	int min_g=INT_MAX;
	for(int _=n_g;_--;){
		int x;std::cin>>x;
		sum_g+=x;
		min_g=std::min(min_g,x);
	}

	if(max_b[0]>min_g){
		std::cout<<"-1\n";
		return 0;
	}
	int64_t ans=sum_b*n_g;
	ans+=sum_g;
	if(max_b[0]==min_g)
		ans-=(int64_t)n_g*max_b[0];
	else
		ans-=int64_t(n_g-1)*max_b[0]+max_b[1];
	std::cout<<ans<<'\n';
}