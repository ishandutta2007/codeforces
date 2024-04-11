/*
 * Trying to solve multiple problems at ones is rarely a good idea.
 * At best it "only" increases the penalty (that's if you're sure that
 * you can solve all of the problems you've attempted)
 *
 * =======
 *
 * >.< Integer overflow bug.
 * Lesson: Just don't use istream_iterator.
 */
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	std::vector<int64_t> b(*std::istream_iterator<int>(std::cin));
	std::copy_n(std::istream_iterator<int64_t>(std::cin),b.size(),begin(b));

	std::vector<int64_t> out;
	for(int clz=2;clz<64;++clz){
		auto iter=std::partition(begin(b),end(b),[&](auto x){ return __builtin_clzll(x)!=clz; });

		decltype(out) out1;
		auto iter_out=begin(out);
		std::for_each(iter,end(b),[&](auto x){
			assert(__builtin_clzll(x)==clz);
			if(not out1.empty()){
				while(true){
					if(iter_out==end(out)){
						std::cout<<"No\n";
						std::exit(0);
						// there's no clear way to break out of `for_each` without using exception? ...
					}
					out1.push_back(*iter_out);
					++iter_out;
					if(out1.back()>>(63^clz)&1) break;
				}
			}
			out1.push_back(x);
		});
		out1.insert(end(out1),iter_out,end(out));

		assert(out1.size()==out.size()+(end(b)-iter));
		b.erase(iter,end(b));
		out=std::move(out1);
	}

	std::cout<<"Yes\n";
	int64_t xorprev=0;
	for(auto x:out){
		std::cout<<x<<' ';
		assert(xorprev<(xorprev xor x));
		xorprev^=x;
	}
	std::cout<<'\n';
}