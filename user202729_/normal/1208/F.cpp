#include<iostream>
#include<vector>

struct item{
	// represent a set of indices with value being a superset of a bitmask.
	int a,b; // a < b are two largest. -1 if not available.
	item():a(-1),b(-1){}
	item(int b):a(-1),b(b){}
	item(item x,item y){
		if(x.b<y.b)std::swap(x,y);
		b=x.b;
		a=std::max(x.a,y.b);
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> val(n);
	int orall=0;
	for(int& x:val){
		std::cin>>x;
		orall|=x;
	}
	
	if(orall==0){
		std::cout<<"0\n";
		return 0;
	}

	auto npattern=2<<(31^__builtin_clz(orall));

	std::vector<item> t(npattern);
	for(int i=0;i<n;++i)
		t[val[i]]=item(t[val[i]],item(i));

	// accumulate from each pattern to subsets (then t[v] = info of supersets of v)
	for(int bit=1;bit<npattern;bit<<=1)
		for(int v=0;v<npattern;++v)
			if(v&bit)
				t[v^bit]=item(t[v^bit],t[v]);

	// for each element being a candidate for i
	int ans=0;
	for(int i=0;i<n-2;++i){
		int mask=(npattern-1)^val[i];
		// find maximum submask v of mask such that t[v] has at least 2 elems
		int v=0;
		for(int bit=npattern;bit>>=1;)if(mask&bit)
			if(t[v|bit].a>=0)
				v|=bit;

		ans=std::max(ans,val[i]|v);
	}
	std::cout<<ans<<'\n';
}