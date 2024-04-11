#include<iostream>
#include<vector>
#include<cmath>
#include<set>

bool has_in_range(std::set<int> const& s,int l,int r){
	// does any value in [l..r] appear in s?
	auto iter=s.lower_bound(l);
	return iter!=s.end()&&*iter<=r;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	// z[g] = set of all pile size >0 with grundy value == g
	std::vector<std::set<int>> z(1);
	z[0].insert(1);
	z[0].insert(2);
	z[0].insert(3);
	int constexpr ENDPILESIZE=1000000;
	for(int pile_size=4,
			a=2, // min value >= pile_size**(1/4)
			b=2; // max value <= pile_size**(1/2)
			pile_size<ENDPILESIZE;++pile_size){
		while(a*a*a*a<pile_size)++a;
		while((b+1)*(b+1)<=pile_size)++b;

		int g=0; // grundy value of a pile of size pile_size
		while(g<z.size()&&has_in_range(z[g],a,b))
			++g;
		if(g==z.size())
			z.emplace_back();
		z[g].insert(pile_size);
	}

	int n;std::cin>>n;
	int g_wholegame=0;
	for(int _=n;_--;){
		int64_t pile_size;std::cin>>pile_size;
		int g=0;
		if(pile_size<ENDPILESIZE){
			while(z[g].find(pile_size)==z[g].end())
				++g;
		}else{
			// use integer arithmetic to compute a & b to avoid possible error
			int a=std::pow(pile_size,1./4)-1;
			while((int64_t)a*a*a*a<pile_size)++a;
			int b=std::sqrt(pile_size)+2;
			while((int64_t)b*b>pile_size)--b;
			while(g<z.size()&&has_in_range(z[g],a,b))
				++g;
		}
		g_wholegame^=g;
	}
	std::cout<<(g_wholegame!=0?"Furlo\n":"Rublo\n");
}