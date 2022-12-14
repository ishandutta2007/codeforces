#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<unordered_set>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int sum1,sum2;std::cin>>sum1>>sum2;
	int bkp1=sum1, bkp2=sum2;
	int first_unread=1;
	std::vector<int> a,b;
	while(first_unread<=sum1){
		a.push_back(first_unread);
		sum1-=first_unread;
		++first_unread;
	}
	int unread_ind=-1;
	if(sum1){
		unread_ind=end(a)[-sum1];
		std::transform(end(a)-sum1,end(a),end(a)-sum1,[](int x){return x+1;});
		++first_unread;
	} // unread set: {unread_ind} + {first_unread ...}

	if(unread_ind>=0 and unread_ind<=sum2){
		b.push_back(unread_ind);
		sum2-=unread_ind;
	}

	while(first_unread<=sum2){
		b.push_back(first_unread);
		sum2-=first_unread;
		++first_unread;
	}

	assert(([&]{
		std::unordered_set<int> s;
		for(auto x:{&a,&b}){
			int64_t sum=0;
			for(auto y:*x){
				auto [i,suc]=s.insert(y);
				assert(suc);
				assert(1<=y);
				sum+=y;
			}
			if(x==&a) assert(sum==bkp1); else assert(sum<=bkp2);
		}
		return true;
	}()));

	std::cout<<a.size()<<'\n';
	for(auto x:a)std::cout<<x<<' ';
	std::cout<<'\n';

	std::cout<<b.size()<<'\n';
	for(auto x:b)std::cout<<x<<' ';
	std::cout<<'\n';
}