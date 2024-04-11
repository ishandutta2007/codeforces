#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<array>

std::vector<std::vector<int>> ad;

std::vector<int> par;
std::vector<char> char_to_par; // not meaningful for root. -1 if '?'.
static_assert(char(-1) < 0);

// for compressed tree:
struct cnt_t{
	private:
	std::array<int,26> c; // [c] = min cnt of char (c) on a path from 
	// this node to any leaf

	public:
	int sum; // should not exceed leaf_depth (otherwise there's no solution)

	void set(int ind,int x){
		sum-=c[ind];
		sum+=c[ind]=x;
	}

	int operator[](int ind)const{
		return c[ind];
	}
};
std::vector<cnt_t> cnt;
std::vector<std::vector<int>> cad;
std::vector<std::array<int,26>> cnt_to_par;
std::vector<int> cpar,cnode,cdt /* depth*/;

int nexceed; // sum {cnt[i].sum > leaf_depth-depth[i]} for compressed i
void compute_cnt(int cnode,char c){
	int out=0;
	for(int y:cad[cnode])
		out=std::max(out,cnt_to_par[y][c]+cnt[y][c]);
	cnt[cnode].set(c,out);
}

struct different_leaf_depth{};

std::vector<int> depth; // for uncompressed nodes
int leaf_depth=-1;
void dd(int x){
	if(ad[x].empty()){
		if(leaf_depth>=0 and leaf_depth!=depth[x])
			throw different_leaf_depth{};
		leaf_depth=depth[x];
		return;
	}
	for(int y:ad[x]){
		depth[y]=depth[x]+1;
		dd(y);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nquery;std::cin>>n>>nquery;
	ad.resize(n);
	par.resize(n);
	char_to_par.resize(n);
	par[0]=-1;
	for(int i=1;i<n;++i){
		int& p=par[i];char c;
		std::cin>>p>>c;--p;
		char_to_par[i]=char(c=='?' ? -1 : c-'a');
		ad[p].push_back({i});
	}

	depth.resize(n);
	depth[0]=0;
	try{
		dd(0); // total O(n)
	}catch(different_leaf_depth){
		while(nquery--)std::cout<<"Fou\n";
		return 0;
	}

	cpar.assign(1,-1);
	cnode.resize(n);cnode[0]=0; // node -> compressed node. if on some edge -> points to lower compressed node.
	cdt.assign(1,0);
	cnt_to_par.assign(1,{}); // for root compressed node cnt_to_par should be all zero
	cad.resize(1);

	for(int i=1;i<n;++i){ // compress tree
		if(ad[par[i]].size()==1 and par[i]!=0){ // can compress
			cnode[i]=cnode[par[i]];
			cdt[cnode[i]]=depth[i];
		}else{ // make new node
			cnode[i]=(int)cpar.size();
			cpar.push_back(cnode[par[i]]);
			cad[cpar[cnode[i]]].push_back(cnode[i]);
			cad.emplace_back();
			cnt_to_par.emplace_back();
			cdt.push_back(depth[i]);
		}
		if(char_to_par[i]>=0)
			++cnt_to_par[cnode[i]][char_to_par[i]];

		assert(cpar.size()==cdt.size());
		assert(cpar.size()==cad.size());
		assert(cpar.size()==cnt_to_par.size());
	}
	// now maximum compressed depth of a leaf is in O(sqrt(n))


#define depth
#define par
#define ad
#define n

	cnt.resize(cpar.size());

	nexceed=0;
	for(int i=(int)cpar.size();i--;){ // n * 26
		for(char c=0;c<26;++c)
			compute_cnt(i,c);
		nexceed+=cnt[i].sum > leaf_depth-cdt[i];
	}

	while(nquery--){
		int node;char c;std::cin>>node>>c;
		--node;
		c=char(c=='?' ? -1 : c-'a');
		if(c!=char_to_par[node]){
			char old=char_to_par[node];
			char_to_par[node]=c;
			if(old>=0) --cnt_to_par[cnode[node]][old];
			if(c>=0) ++cnt_to_par[cnode[node]][c];

			// total q * sqrt(n)
			for(int y=cnode[node];y!=0;){ y=cpar[y]; // for y = strict ancestors of node

				nexceed-=cnt[y].sum > leaf_depth-cdt[y];
				for(char x:{old,c})if(x>=0)
					compute_cnt(y,x);
				nexceed+=cnt[y].sum > leaf_depth-cdt[y];
			}
		}

		if(nexceed>0){
			std::cout<<"Fou\n";
		}else{ // 26
			assert(nexceed==0);
			int n_question_mark=leaf_depth;
			for(int c=0;c<26;++c) n_question_mark-=cnt[0][c];
			assert(n_question_mark>=0);

			int64_t out=0;
			for(int c=0;c<26;++c){
				int fc=n_question_mark+cnt[0][c];
				out+=(c+1LL)*fc;
			}
			std::cout<<"Shi "<<out<<'\n';
		}
	}
}