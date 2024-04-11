#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> ad,ad_tree;
std::vector<char> mark,visited; // ancestors of a node int some cycle, or root
std::vector<int> par;
std::vector<int> score;

void dfs(int a,int pa){
	visited[a]=true;
	for(int b:ad[a])if(b!=pa){
		if(visited[b]){
			for(int c=b;!mark[c];c=par[c])
				mark[c]=true;
		}else{
			ad_tree[a].push_back(b);
			dfs(b,par[b]=a);
		}
	}
}

std::vector<int64_t> sp; // sum of weight of all unmarked ancestor of this node

void dfs2(int a){
	// sp[a] must be filled
	for(int b:ad_tree[a]){
		sp[b]=mark[b]?0:sp[a]+score[b];
		dfs2(b);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nedge;std::cin>>n>>nedge;
	score.resize(n);
	for(int& x:score)std::cin>>x;

	ad.resize(n);
	for(int _= nedge;_--;){
		int u,v;std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	int root;std::cin>>root;--root;
	mark.resize(n);par.resize(n);
	visited.resize(n);
	mark[root]=true;
	ad_tree.resize(n);
	dfs(root,-1);

	sp.resize(n);
	dfs2(root);
	int64_t ans=0;
	for(int i=0;i<n;++i)
		if(mark[i])ans+=score[i];
	ans+=*std::max_element(begin(sp),end(sp));

	std::cout<<ans<<'\n';
}

// NOTE test n=1 or nedge=0