#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<vector>
#include<string>
#include<iostream>

struct circuit{
	enum class type{ s,p,unit } t;
	std::vector<circuit> sub;
	int64_t val; // min sum for resistance r = val*val*r

	circuit():
		t(type::unit),
		sub(),
		val(1)
	{}

	circuit(char type,std::vector<circuit>::iterator first,std::vector<circuit>::iterator last):
		t(type=='S' ? type::s : type::p),
		sub(std::make_move_iterator(first),std::make_move_iterator(last)),
		val()
	{
		assert(type=='S' or type=='P');
		calc();
	}

	circuit(circuit const&)=delete; // don't copy unnecessarily
	circuit(circuit&&)=default;
	circuit& operator=(circuit const&)=delete;
	circuit& operator=(circuit&&)=default;

	void calc(){
		if(t==type::s){
			val=INT64_MAX;
			for(auto& c:sub)
				val=std::min(val,c.val);
		}else{
			assert(t==type::p);
			val=0;
			for(auto& c:sub)
				val+=c.val;
		}
	}

	// print a construction to get resistance r1/val
	void print(int64_t r1)const{
		switch(t){
			case type::unit:
				assert(val==1);
				std::cout<<r1 <<' ';
				break;
			case type::s:
				{
					bool found =false;
					for(auto const& c:sub){
						if(not found and c.val==val){
							c.print(r1);
							found =true;
						}else{
							c.print(0);
						}
					}
				}
				break;
			case type::p:
				for(auto const& c:sub){
					c.print(r1);
				}
				break;
		}
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	std::string line;
	while(ntest--){
		std::vector<circuit> st;
		std::vector<char> ops;

		int r;std::cin>>r;
		std::getline(std::cin,line);

		for(char c:line)
			switch(c){
				case ' ':
					break;

				case '*':
					st.push_back({});
					break;

				case 'S':
				case 'P':
				case '(':
					ops.push_back(c);
					break;

				case ')':
					{
						if(ops.back()=='('){ // invalid
							ops.pop_back();
							break;
						}
						auto nparam=1+(std::find(ops.rbegin(),ops.rend(),'(')-ops.rbegin());
						assert(nparam>=2);
						char type=ops.back();
						ops.erase(end(ops)-nparam,end(ops));

						auto iter=end(st)-nparam;
						assert(type=='S' or type=='P');
						circuit out{type, iter,end(st)};
						st.erase(iter,end(st));
						st.push_back(std::move(out));
						break;
					}

				default:
					assert(false);
					__builtin_unreachable();
			}

		assert(st.size()==1);
		assert(ops.empty());
		circuit c=std::move(st.back());
		st.pop_back();

		std::cout<<"REVOLTING ";
		c.print(r*c.val);
		std::cout<<'\n';
	}
}