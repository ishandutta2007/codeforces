#include<iostream>
#include<array>
#include<vector>
#include<climits>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nquery;std::cin>>n>>nquery;
	std::string s;s.reserve(n);
	std::cin>>s;

	std::vector<std::array<int,26>> nxt(s.size()); // nxt[i][ch] = min j>i such that s[j-1]==ch or INT_MAX
	{
		std::array<int,26> nxtc;
		std::fill(begin(nxtc),end(nxtc),INT_MAX);
		for(unsigned i=s.size();i--;){
			nxtc[s[i]-'a']=i+1;
			nxt[i]=nxtc;
		}
	}

	// f[a][b][c] = min i such that t1[:a], t2[:b], t3[:c] can coexist int s[:i]
	std::vector<std::array<std::array<int,251>,251>> f(251);
	for(auto& fx:f)
		for(auto& fxy:fx)
			std::fill(begin(fxy),end(fxy),INT_MAX);
	f[0][0][0]=0;

	using i3=std::array<int,3>;
	std::array<std::vector<char>,3> t;

	while(nquery--){
		char type,dim;std::cin>>type>>dim;
		dim-='1';
		if(type=='+'){
			{
				char ch;std::cin>>ch;
				t[dim].push_back(ch-'a');
			}

			i3 ind;
			ind[dim]=t[dim].size();

			auto const d1=(dim+1)%3,d2=(dim+2)%3;
			for(ind[d1]=0;ind[d1]<=(int)t[d1].size();++ind[d1])
			for(ind[d2]=0;ind[d2]<=(int)t[d2].size();++ind[d2]){
				int ans=INT_MAX;
				for(int j=0;j<3;++j)
					if(ind[j]!=0){
						--ind[j];
						if(f[ind[0]][ind[1]][ind[2]]<n){
							ans=std::min(ans,
									nxt[
									f[ind[0]][ind[1]][ind[2]]
									][
									t[j][ind[j]]
									]
									);
						}
						++ind[j];
					}
				f[ind[0]][ind[1]][ind[2]]=ans;
			}
		}else
			t[dim].pop_back();

		std::cout<<(f[t[0].size()][t[1].size()][t[2].size()]!=INT_MAX?"YES\n":"NO\n");
	}
}