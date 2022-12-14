// Note: it's **wrong** to "overflow" the valid range then check when inside.
// The correct options are:
// * Run past one r, then undo (remember to handle the special case when the range is empty when increment l)
// * Run past one r, then consider the r-1 option
// * For each r, find valid l [implemented here. I think it's shorter than the previous solution]
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<set>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nsong,maxpart,maxtime;std::cin>>nsong>>maxpart>>maxtime;
	std::vector<int> pl(nsong);for(int& x:pl)std::cin>>x;
	std::vector<int> t(nsong);for(int& x:t)std::cin>>x;

	int l=0,r=0;
	std::multiset<int> partt // set of t values of partially-listened songs
		,fullt;
	int64_t sumtime=0;
	// to minimize (sumtime), it's preferred to put the large elements in partt

	auto addpart=[&](int x){
		partt.insert(x);
		sumtime+=(x+1)/2;
	};
	auto delpart=[&](int x){
		partt.erase(partt.find(x));
		sumtime-=(x+1)/2;
	};
	auto addfull=[&](int x){
		fullt.insert(x);
		sumtime+=x;
	};
	auto delfull=[&](int x){
		fullt.erase(fullt.find(x));
		sumtime-=x;
	};

	int64_t sum_pleasure=0,max_pleasure=0;
	while(r<nsong){
		assert(l<=r);
		if(l==r) assert(sumtime==0 and sum_pleasure==0);

		// add r
		if((int)partt.size()==maxpart){
			if(t[r]<=*partt.begin())
				addfull(t[r]);
			else{
				addpart(t[r]);
				addfull(*partt.begin());
				delpart(*partt.begin());
			}
			assert((int)partt.size()==maxpart);
		}else{
			assert(fullt.empty());
			addpart(t[r]);
		}

		sum_pleasure+=pl[r];
		++r;

		while(sumtime>maxtime){
			// remove l
			assert(not partt.empty());
			if(*partt.begin()<=t[l]){
				delpart(t[l]);
				if(not fullt.empty()){
					addpart(*fullt.rbegin());
					delfull(*fullt.rbegin());
				}
			}else
				delfull(t[l]);

			sum_pleasure-=pl[l];
			++l;
		}

		max_pleasure=std::max(max_pleasure,sum_pleasure);
	}
	std::cout<<max_pleasure<<'\n';
}