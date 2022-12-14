#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

int main(){auto&O=std::cout;
#ifdef _GLIBCXX_DEBUG
std::stringstream I(R"(
23
-51233 -29011 76503 -67974 -58789 -1739 41856 87617 -95938 14915 -83343 31109 1360 -78056 3267 -73944 -56292 -51033 -69867 33240 80417 50832 -41267
)");
#else
auto&I=std::cin;std::ios::sync_with_stdio(0);I.tie(0);
#endif

int n;I>>n;
std::vector<int> a(n+1);
while(n--)I>>a[n];
std::sort(a.begin(),a.end());
a.erase(std::unique(a.begin(),a.end()),a.end());

// let (-b) be the smallest representable number. Consider k in [0..19], and let A[k] be
// (there exists card 2^k or -2^k). So nAZero[b] is number of '0's in A[0..19].
std::vector<int> nAZero(1<<18);
for(int k=0;k<18;++k){
	unsigned rangeMin=0,rangeMax=1<<k; // range [min..max[ of values of (-b) s.t. A[k]==0.
	// note that it's guaranteed that 0 is in (a).
	for(int x:a){
		// if A[k]==0 then x+(-b) should have bit[k] zero <-> x+(-b) mod 2^(k+1) < 2^k
		// (-b) mod 2^(k+1) in [0..2^k]+(-x mod 2^(k+1))
		unsigned offset=(-x)%(2u<<k); // note the 'u'. = (-x mod 2^(k+1))
		if(offset<(1u<<k)){
			// range [offset..offset+2^k[
			rangeMin=std::max(rangeMin,offset);
			rangeMax=std::min(rangeMax,offset+(1u<<k));
		}else{
			// range [offset..2*2^k[ union [0..offset-2^k[. the first one obviously
			// has no intersection with [0..2^k[.
			rangeMax=std::min(rangeMax,offset-(1u<<k));
		}
	}
	if(rangeMin>=rangeMax)
		continue; // the range is empty, this bit can't be zero...
	for(unsigned neg_b=0;neg_b<nAZero.size();++neg_b){
		if(rangeMin<=neg_b%(2u<<k)&&neg_b%(2u<<k)<rangeMax)
			++nAZero[neg_b];
	}
}

// next: find maximum (nAZero) and corresponding (b)
int min_a=*std::min_element(a.begin(),a.end()); // zero or negative
unsigned neg_b=std::max_element(nAZero.begin()-min_a,nAZero.end())-nAZero.begin();
std::vector<char> A(18); // 1 <-> 
for(int x:a){
	for(int k=0;k<18;++k){
		if((x+neg_b)&(1<<k)){
			A[k]=true;
		}
	}
}
O<<std::count(A.begin(),A.end(),true)<<'\n';
for(int k=0;k<18;++k){
	if(not A[k])continue;
	O<<(((neg_b&(1<<k))?-1:1)<<k)<<' ';
}
O<<'\n';

}