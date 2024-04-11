// I still have no idea how to solve the problem int O(n) memory...
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<deque>
#include<array>
#include<algorithm>
#include<climits>

struct node{
	char paredge;
	int child,sib; // 0: none
};
std::deque<node> trie;

struct child_iter{
	int x;
	auto operator*()const{return x;}
	void operator++(){
		assert(x!=0);
		x=trie[x].sib;
	}
};
struct child_iter_end{};

auto operator!=(child_iter a,child_iter_end){
	return a.x!=0;
};

struct child_range{
	int x;
	child_iter begin()const{return child_iter{trie[x].child};}
	child_iter_end end()const{return {};}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int slen,cost1,costn;
	std::cin>>slen>>cost1>>costn;

	std::string s;s.reserve(slen);
	std::cin>>s;
	for(char& c:s)c-='a';

	trie.resize(1);
	trie[0].paredge=-1;

	std::vector<int> dp(slen+1,INT_MAX);
	dp[0]=0;
	std::vector<int> node(slen); // node[start] ~ s[start:i]
	for(int i=0;;){
		dp[i+1]=std::min(dp[i+1],dp[i]+cost1);
		{
			int r=i,nodeir=0;
			while(r<slen){
				for(int child:child_range{nodeir})
					if(trie[child].paredge==s[r]){
						nodeir=child;
						++r;
						dp[r]=std::min(dp[r],dp[i]+costn);
						goto cont_outer;
					}

				break;
cont_outer:;
			}
		}

		++i;
		if(i==slen)break;
		for(int start=0;start<i;++start){
			for(int child:child_range{node[start]})
				if(trie[child].paredge==s[i-1]){
					node[start]=child;
					goto next_start_val;
				}

			{
				auto oldchild=trie[node[start]].child;
				trie[node[start]].child=(int)trie.size();
				node[start]=(int)trie.size();
				trie.push_back({.paredge=s[i-1], .child=0, .sib=oldchild});
			}
next_start_val:;
		}
	}
	std::cout<<dp[slen]<<'\n';
}