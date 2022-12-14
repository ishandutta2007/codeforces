// :(

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

auto digits(int64_t it){
	std::array<char, 19> result{};
	auto iterator=result.rbegin();
	while(it){
		*iterator++=char(it%10); it/=10;
	}
	return result;
}

int64_t solve(int64_t leftValue, int64_t rightValue){
	auto const left=digits(leftValue), right=digits(rightValue);
	auto const matchLength=int(std::mismatch(begin(left), end(left), begin(right)).first-begin(left));

	int64_t result=1;
	for(int prefix=0; prefix<19; ++prefix)
	for(int next=left[prefix]+1; next<=9;++next){
		if(prefix<=matchLength and next>right[prefix]) continue;
		auto const strictlyLessR=prefix>matchLength or next<right[prefix];
		// ^ for l[:prefix]+next

		{
			std::array<std::array<int64_t, 10>, 2> value{};
			value[strictlyLessR][0]=1;
			for(int cur=prefix+1; cur<19;++cur){
				auto const old=value; value={};
				for(int lessr=0; lessr<2;++lessr)
					for(int last=0; last<10;++last){
						auto const curOld=old[lessr][last];
						if(curOld==0) continue;

						for(int next1=last; next1<10;++next1){
							if(next1<next and next1>=left[prefix]) continue;
							if(not lessr and next1>right[cur]) break;
							value[lessr or next1<right[cur]][next1]+=curOld;
						}
					}
			}
			for(auto it: value)for(auto it: it) result+=it;
		}

		for(int pos=prefix+1; pos<19;++pos){
			std::array<std::array<std::array<int64_t, 10>, 2>, 2> value{};
			value[false][strictlyLessR][0]=1;
			for(int cur=prefix+1; cur<19;++cur){
				auto const old=value; value={};
				for(int lessl=0; lessl<2;++lessl)
				for(int lessr=0; lessr<2;++lessr)
					for(int last=0; last<10;++last){
						auto const curOld=old[lessl][lessr][last];
						if(curOld==0) continue;

						for(int next1=last; next1<10;++next1){
							if(next1<next and next1>left[prefix]) continue;
							if(cur==pos and next1!=left[prefix]) continue;
							if(cur>pos and next1<next) continue;
							if(not lessr and next1>right[cur]) break;
							auto const valueSwapped=cur==pos ? next: next1;
							value[lessl ? valueSwapped<=left[19-cur+prefix]
								: (valueSwapped<left[19-cur+prefix])
							][lessr or next1<right[cur]][next1]+=curOld;
						}
					}
			}
			for(auto it: value[1])for(auto it: it) result+=it;
		}
	}

	assert(([&]{
		std::set<decltype(digits(0))> set;
		for(auto x=leftValue; x<=rightValue;++x) {
			auto t=digits(x);
			std::sort(begin(t), end(t));
			set.insert(t);
		}
		auto const tmp=(int64_t)set.size();
		assert(result==tmp);
		return true;
	}()));
	return result;
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	/*
	for(int len=1; len<1000;++len){
		for(int left=1; left<1000;++left)
			solve(left, left+len);
	}
	*/


	int64_t leftValue, rightValue; std::cin>>leftValue>>rightValue;
	std::cout<<solve(leftValue, rightValue)<<'\n';
}