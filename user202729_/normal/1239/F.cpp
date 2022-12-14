#include<iostream>
#include<climits>
#include<queue>
#include<algorithm>
#include<array>
#include<cassert>
#include<vector>

std::vector<std::vector<int>> ad;

std::vector<char> vis;
std::vector<int> par,dt; // parent, depth

void bfs(int root){
	assert(!vis[root]);
	std::queue<int> q;
	vis[root]=true;q.push(root);
	par[root]=-1;dt[root]=0;

	while(!q.empty()){
		int x=q.front();q.pop();
		int const nextdt=dt[x]+1;
		for(int y:ad[x])
			if(!vis[y]){
				vis[y]=true;q.push(y);
				par[y]=x;
				dt[y]=nextdt;
			}
	}
}



void solve(){
	ad.clear();vis.clear();par.clear();dt.clear();

	int n,m;std::cin>>n>>m;
	if(n==1){
		assert(m==0);

retno:
		std::cout<<"No\n";
		return;
	}
	ad.clear();ad.resize(n); // http://quick-bench.com/gA_4mEfAnrl2lETqG9pkGqad05U
	for(int _=0;_<m;++_){
		int a,b;std::cin>>a>>b;--a;--b;
		ad[a].push_back(b);
		ad[b].push_back(a);
	}

	std::vector<char> keep(n,true);
	auto const printall=[&, bkp_ad=ad]()->void{
		auto const ndelete=std::count(begin(keep),end(keep),false);
		assert(ndelete);
		std::cout<<"Yes\n"<<ndelete<<'\n';
		for(int i=0;i<n;++i){
			if(keep[i])
				assert((
							bkp_ad[i].size()-
							std::count_if(begin(bkp_ad[i]),end(bkp_ad[i]),[&](int j){return keep[j];})
					   )%3==0);
			else
				std::cout<<i+1<<' ';
		}
		std::cout<<'\n';
	};

	std::vector<int> deg(n);
	for(int i=0;i<n;++i){
		deg[i]=int(ad[i].size()%3);
		if(deg[i]==0){
			keep.assign(n,false);
			keep[i]=true;
			return printall();
		}
	}

	int i=int(std::find(begin(deg),end(deg),1)-begin(deg));
	if(i==n)
		i=0;

	vis.assign(n,false);
	par.resize(n);
	dt.resize(n);
	bfs(i);

	if(std::find(begin(vis),end(vis),false)!=end(vis)){
		// multiple connected components. remove the visited component
		for(int i=0;i<n;++i)
			if(vis[i])
				keep[i]=false;
		return printall();
	}

	if(std::all_of(begin(ad),end(ad),[](auto const& x){return x.size()<3;}))
		goto retno;

	if(deg[i]==1){
		int mindt=INT_MAX;
		for(int j=0;j<n;++j)
			if(j!=i and deg[j]==1)
				mindt=std::min(mindt,dt[j]);

		for(int j=0;j<n;++j)
			if(j!=i and deg[j]==1 and dt[j]==mindt){
				assert(vis[j]); // two connected node-1
				// path i..j int bfs tree is (one of) the shortest paths

				vis.assign(n,false);
				int ndelete=n-1;
				vis[i]=true;
				for(int x=j;x!=i;x=par[x]){
					--ndelete;
					vis[x]=true;
				}

				for(int k=0;k<n;++k)
					if(!vis[k])
						keep[k]=false;
				return printall();
			}
	}

	// otherwise there's at most one node with degree 1
	for(int j=0;j<n;++j)
		if(j!=i)
			assert(deg[j]==2);

	// temporarily remove
	if(deg[i]==1)
		for(int j:ad[i])
			ad[j].erase(std::find(begin(ad[j]),end(ad[j]),i));

	// find a cycle consisting of only node 2 int the tree
	vis.assign(n,false);
	int cc_id=0; // connected component index
	std::vector<char> old_vis;

	int root1,leaf1,root2,leaf2; // also compute some info for next case

	for(int j:ad[i]){
		assert(deg[j]==2);
		if(!vis[j]){
			if(cc_id==1){
				assert(deg[i]==1); // otherwise the whole graph must be connected
				root1=ad[i][0];

				leaf1=-1;
				for(auto iter=++begin(ad[i]);iter!=end(ad[i]);++iter)
					if(vis[*iter]&& ( leaf1<0 || dt[*iter]<dt[leaf1] ))
						leaf1=*iter;

				old_vis=vis;
			}
			bfs(j); // will not visit node i
			if(cc_id==1){
				root2=j;

				leaf2=-1;
				for(auto iter=++begin(ad[i]);iter!=end(ad[i]);++iter)
					if(vis[*iter]&&!old_vis[*iter]&&j!=*iter&& ( leaf2<0 || dt[*iter]<dt[leaf2] ))
						leaf2=*iter;
			}
			++cc_id;
		}
	}
	// if deg[i]==1, bfs root(s) are the nodes adjacent to node i
	// otherwise the root does not matter

	int bestj,bestk,min_sum_depth=INT_MAX;
	for(int j=0;j<n;++j)if(deg[j]==2)
		for(int k:ad[j]){
			assert(deg[k]==2);
			if(dt[k]<=dt[j]&&k!=par[j]){
				// found a candidate. remove j..k path (false nodes are kept)
				if(dt[j]+dt[k]<min_sum_depth){
					min_sum_depth=dt[j]+dt[k];
					bestj=j;bestk=k;
				}
			}
		}

	// add back removed edges
	if(deg[i]==1)
		for(int j:ad[i])
			ad[j].push_back(i);

	if(min_sum_depth!=INT_MAX){ // {bestj,bestk} : min sum_depth ==> irreducible candidate
		vis.assign(n,true);
		for(int x=bestj;x>=0;x=par[x])
			vis[x]=false;
		for(int x=bestk;;x=par[x]){
			if(vis[x]==false){
				for(int y=par[x];y>=0;y=par[y])
					vis[y]=true; // ]lca .. root]: not int path
				break;
			}
			assert(x>=0); // j and k must be in the same forest
			vis[x]=false;
		}

		for(int x=0;x<n;++x)
			if(vis[x])
				keep[x]=false;
			else{
				// kept node
				assert(deg[x]==2);
				assert(std::count_if(begin(ad[x]),end(ad[x]), /* inc. the node-1 */
							[&](int z){return !vis[z] /* kept */ ;})==2);
			}
		return printall();
	}

	// otherwise: node 2 forms forest
	assert(deg[i]==1);
	vis.assign(n,true); // (false nodes are kept)
	vis[i]=false;

	assert(leaf1!=root1 && leaf1!=i&&leaf1>=0);
	assert(leaf2!=root2 && leaf2!=i&&leaf2>=0);
	assert(deg[root1]==2); assert(deg[leaf1]==2);
	assert(deg[root2]==2); assert(deg[leaf2]==2);

	std::sort(begin(ad[i]),end(ad[i]));
	assert(std::binary_search(begin(ad[i]),end(ad[i]),root1));
	assert(std::binary_search(begin(ad[i]),end(ad[i]),leaf1));
	assert(std::binary_search(begin(ad[i]),end(ad[i]),root2));
	assert(std::binary_search(begin(ad[i]),end(ad[i]),leaf2));

	for(auto xy:{std::pair<int,int>{leaf1,root1},{leaf2,root2}}){
		auto [x,y]=xy;
		while(true){
			assert(x>=0);
			vis[x]=false;
			x=par[x];
			if(x==y){
				vis[y]=false;
				break;
			}
		}
	}

	assert(vis[root1]==false);
	assert(vis[root2]==false);

	auto const ndelete=std::count(begin(vis),end(vis),true);
	if(ndelete==0)
		goto retno;

	for(int x=0;x<n;++x)
		if(vis[x])
			keep[x]=false;
		else{
			if(deg[x]==2){
				assert(std::count_if(begin(ad[x]),end(ad[x]), /* inc. the node-1 (i) */
							[&](int z){return !vis[z] /* kept */ ;})==2);
			}
		}
	return printall();

}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int t;std::cin>>t;
	while(t--)
		solve();
}