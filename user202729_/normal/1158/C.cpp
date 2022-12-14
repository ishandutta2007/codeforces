#include<iostream>
#include<vector>

int n;
std::vector<std::vector<int>> ad;

std::vector<int> ans,num;
enum class state{ white,gray,black };
std::vector<state> st;
int last_ans;

struct cycle_detected_error{};

void dfs(int x,int par){
	st[x]=state::gray;
	for(int y:ad[x])if(y!=par){ // no multiple edges
		if(st[y]==state::gray)
			throw cycle_detected_error{};
		if(st[y]==state::white)
			dfs(y,x);
		// else: cross edge
	}
	st[x]=state::black;
	if(x>=n)
		ans[x-n]=--last_ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		std::cin>>n;
		ad.clear();ad.resize(2*n);

		for(int i=2;i<2*n;++i)
			ad[i].push_back(i>>1);

		for(int i=0;i<n;++i){
			int nxt;std::cin>>nxt;
			if(nxt<0)continue;
			--nxt;

			int node_i=i+n;

			int l=i+1+n,r=nxt+n;
			while(l<r){
				if(l&1)ad[l++].push_back(node_i);
				if(r&1)ad[--r].push_back(node_i);
				l>>=1;r>>=1;
			}

			if(nxt<n)
				ad[node_i].push_back(nxt+n);
		}

		last_ans=n+1;
		ans.clear();ans.resize(n);
		st.assign(2*n,state::white);
		try{
			for(int i=n;i<2*n;++i)
				if(st[i]==state::white)
					dfs(i,-1);
		}catch(cycle_detected_error){
			std::cout<<"-1\n";
			continue;
		}
		for(int x:ans)std::cout<<x<<' ';
		std::cout<<'\n';
	}

}