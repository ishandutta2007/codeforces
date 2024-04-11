// "forgot" to prove correctness before implementing
//
// ======
// still unproven, but feels more correct

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

std::vector<std::vector<int>> add;
std::vector<std::array<int, 3>> deep; // maximum depth, sorted in the increasing order.
std::vector<int> par;

std::vector<int> updeep; // depth upward -- 0 for root, at least 1 for the rest

void work(int node, int parNode){
	par[node]=parNode;
	std::array<int, 4> cur{};
	for(auto other: add[node]) if(other!=parNode){
		work(other, node);
		cur[0]=deep[other].back()+1;
		{
			int i=0;
			while(i+1<(int)cur.size() and cur[i]>cur[i+1]){
				std::swap(cur[i], cur[i+1]);
				++i;
			}
		}
	}
	std::copy(cur.begin()+1, cur.end(), deep[node].begin());
}
void work2(int node, int parNode, int upnode){
	auto const cur=deep[node];
	updeep[node]=upnode;
	for(auto other: add[node]) if(other!=parNode){
		work2(other, node, std::max(upnode, cur.end()[-1-(deep[other].back()+1==cur.back())])+1);
	}
}

int depth(int node){return node<0 ? -1: depth(par[node])+1;} // naive depth function.

void up(){
	int number, head, tail; std::cin>>number>>head>>tail;
	--head;--tail;
	add.clear(); add.resize(number);
	for(int _=0; _<number-1; ++_){
		int first, sec; std::cin>>first>>sec;--first;--sec;
		add[first].push_back(sec); add[sec].push_back(first);
	}

	int root;

	par.resize(number);
	deep.resize(number);
	work(0, -1);

	auto const lca=[&](int a, int b){
		auto da=depth(a), db=depth(b);
		while(da>db){ a=par[a]; --da; }
		while(db>da){ b=par[b]; --db; }
		assert(da==db);
		while(a!=b){ a=par[a]; b=par[b]; --da; }
		return a;
	};

	auto const len=[&]{
		return depth(head)+depth(tail)-depth(lca(head, tail))*2;
	}();

	for(int node=0; node<number; ++node){
		assert(std::is_sorted(begin(deep[node]), end(deep[node])));
		if(deep[node][0]>=len){
			root=node;
			goto found_root;
		}
	}

	updeep.resize(number);
	work2(0, -1, 0);
	for(int node=0; node<number; ++node){
		if(updeep[node]>=len and deep[node][1]>=len){
			root=node;
			goto found_root;
		}
	}

	std::cout<<"NO\n";
	return;

found_root:
	work(root, -1);
	updeep.clear();

	auto const dhead=depth(head), dtail=depth(tail);
	auto a=head, b=tail, da=dhead, db=dtail;
	auto const dlca=depth(lca(head, tail));

	if(dlca==std::min(dhead, dtail)){
		std::cout<<"YES\n"; return;
	}
	bool useful;
	do{
		useful=false;

		auto const ma=da+deep[a].back();
		assert(ma>=dhead);
		auto const dtail1=dtail-(ma-dhead);
		assert(dtail1<=db);
		if(dtail1<=dlca){
			std::cout<<"YES\n"; return;
		}
		while(db>dtail1){ b=par[b]; --db; useful=true; }

		auto const mb=db+deep[b].back();
		assert(mb>=dtail);
		auto const dhead1=dhead-(mb-dtail);
		assert(dhead1<=da);
		if(dhead1<=dlca){
			std::cout<<"YES\n"; return;
		}
		while(da>dhead1){ a=par[a]; --da; useful=true; }
	}while(useful);

	std::cout<<"NO\n";
}