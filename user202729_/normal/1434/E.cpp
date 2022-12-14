// Apparently yes.
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct Tree{
	std::vector<int> data;
	std::vector<int> changedList;

	Tree(int size): data(size*2, INT_MIN), changedList() {}

	int offset()const{
		return int(data.size()/2);
	}

	void fastReset(){
		for(auto node: changedList) data[node]=INT_MIN;
		changedList.clear();
	}

	void setMaximum(int left, int right, int value){
		auto const process=[&](int node){
			if(data[node]==INT_MIN)
				changedList.push_back(node);

			data[node]=std::max(data[node], value);
		};

		for( left+=offset(), right+=offset();
				left!=right;
				left>>=1, right>>=1){
			if(left&1) process(left++);
			if(right&1) process(--right);
		}
	}

	__attribute__((pure)) int operator[](int index) const{
		int result=INT_MIN;
		for(int node=index+offset(); node; node>>=1)
			result=std::max(result, data[node]);
		return result;
	}
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;

	int resultAll{};


	std::vector<Tree> data; // reuse the data structure to avoid memset time
	int const globalMaxValue=100000;

	for(int _=0; _<number; ++_){
		int len; std::cin>>len;
		assert(len>=1);
		std::vector<int> value(len); for(auto& it: value) std::cin>>it;
		assert(std::is_sorted(begin(value), end(value)));
		assert(value.back()<=globalMaxValue);


		if(number==1){
			assert(len!=0);
			std::cout<<"YES\n";
			return 0;
		}


		for(auto& it: data) it.fastReset();
		// if _3, the amortized complexity of this function is just existing+20*(number<=1000)

		//int const maxValue=value.back();


		// data[g][a] = maximum b such that f(a, b)==g (and b in value), or INT_MIN
		// conjecture: there are only log(maxValue) distinct data values (_3)

		// update: _3 was wrong. (really?)
		// so result==447 with 1e5 values.
		// Let's special-case it.

		// grundy value of states reachable from the initial state.
		// Used to compute mex -> grundy value of the initial state.
		std::vector<char> initialMark(value.size()); // total complexity: 1e5

		// f(a, b) | b in value = grundy value, last=a
		for(auto index=value.size(); index--;){ // total number of iterations: 1e5
			int const b=value[index];

			/*
			compute all f(*, b) values
			
			formula:
			f(a, b)=Mex f(b, c) |c>2b-a
			
			properties:
			f(a, b)<=f(a+1, b)
			a<=b
			
			to compute:
			* for all a, f(a, b)>=0
			* find a0 = minimum a such that {f(b, c)} >= {0} <=> f(a, b)>=1
			so a0=2*b-(maximum c0 such that {f(b, c) | c>c0} >= {0})
			c0 = (maximum c0 such that {f(b, c) | c>c0} >= {0})
			= (maximum c0 such that 0 in {f(b, c) | c>c0})
			= (maximum c0 such that any(f(b, c)==0 | c>=c0+1))
			= (maximum c0' such that any(f(b, c)==0 | c>=c0'))-1
			= (maximum c0' such that f(b, c0')==0)-1
			= data[0][b]-1
			a0=2*b+1-data[0][b]
			
			find a1>=a0 = maximum a such that {f(b, c)} >= {0, 1} <=> f(a, b)>=2
			a1=max(a0, 2*b+1-data[1][b])
			
			similarly, a_i = max(a_(i-1), 2*b+1-data[i][b])
			where a_(-1) = 0  (given that all data values (values in `value`) are >0)
			
			if data[][]==INT_MIN, then a_i==INT_MAX i.e. there's no f(a, b)==i+1
			
			assert(a_i==INT_MAX or a_i<=b for all i);


			update the data structure
			f[0..a_0][b] = 0    -> data[0][0..a_0]   max= b
			f[a_0..a_1][b] = 1  -> data[1][a_0..a_1] max= b
			...
			
			similarly, data[j][a_(j-1)..a_i] max= b  for all 0<=j<=i.
			special case: set a_i=min(a_i, b) (_2)
			*/


			for(int i=0, lasta=0;; ++i){ // if _3 then i<=20
				// => each loop iteration does 20*log(globalMaxValue) ~= 400 steps at most
				// excluding _4
				// => total: 1e5*400=4e7.

				int ai;
				if(i>=(int)data.size() or data[i][b]==INT_MIN){
					assert(lasta<=b+1);
					ai=b+1; // _2
				}else{
					// at the moment, data[i][b]>=b if it's not INT_MIN (it's only set at _1)
					// so b*2+1-data[i][b] <= b+1
					ai=std::max(lasta,
						b*2+1-data[i][b]
						);
					assert(ai<=b+1);
				}

				assert((int)data.size()>=i);
				if(i==(int)data.size()) // _4
					data.emplace_back(globalMaxValue+1); // total complexity: data.size()*globalMaxValue
				// <= 20*1e5 == 2e6 if _3
				// -> 4e6 int in main, 4e6 for fastReset -> 8e6 int -> 32 MB
#if 0
				for(int j=lasta; j<ai; ++j)
					data[i][j]=std::max(data[i][j], b);
#else
				assert(lasta<=ai);
				data[i].setMaximum(lasta, ai,  b); // _1
#endif

				if(ai==b+1){
					assert(lasta<ai);
					// a state with g==f[b][b] == i is reachable from the initial state
					if(i<(int)initialMark.size())
						initialMark[i]=true; // this line is run at most value.size()==initialMark.size() times
					break;
				}
				lasta=ai;
			}
		}

		int result=int(std::find(begin(initialMark), end(initialMark), false)-initialMark.begin());
		// grundy value of the initial state

		resultAll^=result;
	}
	std::cout<<(resultAll!=0 ? "YES\n": "NO\n");
}