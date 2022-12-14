// nevermind.
#ifndef LOCAL
#define NDEBUG
#endif
#include<iomanip>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;

	std::vector<std::vector<int>> d(n,std::vector<int>(n,INT_MAX/2));
	std::vector<std::vector<int>> ad(n);

	for(int z=m;z--;){
		int u,v;std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
		d[u][v]=d[v][u]=1;
	}

	for(int i=n;i--;)
		d[i][i]=0;
	for(int k=n;k--;)
	for(int i=n;i--;)
	for(int j=n;j--;)
		d[i][j]=std::min(d[i][j],d[i][k]+d[k][j]);

	std::vector<std::vector<std::vector<int>>> byd(n); // byd[i][dist] = {x: d[i][x] == dist}
	for(int i=n;i--;){
		auto& bydi=byd[i];
		bydi.resize(1+*std::max_element(begin(d[i]),end(d[i])));
		for(int j=n;j--;)
			bydi[d[i][j]].push_back(j);
	}

	std::vector<double> mark;
	std::vector<char> distseen(n);
	std::vector<std::pair<double,int>> markvals; // {val,ind}
	markvals.reserve(n);

	double ans=0;
	for(int x=n;x--;){ // first chosen vertex
		double cur=0;
		for(unsigned dx=0;dx<byd[x].size();++dx){ // reported distance
			int const ci=(int)byd[x][dx].size();
			assert(ci>0);
			double zz=1./ci;

			if(ci>1){
				mark.assign(n,0);
				for(int j:byd[x][dx]){
					for(int k:ad[j]) // surprisingly the time complexity is only O(n^3)
						mark[k]+=1/(double)ad[j].size();
				}
				// mark[k] / ci = probability for Limak to travel to k

				markvals.clear();
				for(int j=n;j--;){
					if(mark[j])
						markvals.push_back({mark[j],j});
					std::sort(begin(markvals),end(markvals),[](auto a,auto b){return a.first>b.first;});
				}

				double max_smprob=0;
				for(int z=n;z--;){
					double smprob=0; // sum of max probability * ci
					for(auto [prob,j]:markvals)
						if(!distseen[d[z][j]]){
							distseen[d[z][j]]=true;
							smprob+=prob;
						}

					max_smprob=std::max(max_smprob,smprob);

					for(auto [prob,j]:markvals)
						distseen[d[z][j]]=false;
				}

				zz=std::max(zz,max_smprob/(double)ci);
			}

			cur+=zz*ci/n;
		}
		ans=std::max(ans,cur);
	}
	std::cout<<std::setprecision(12)<<std::fixed<<ans<<'\n';
}