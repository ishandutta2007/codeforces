#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<string>
#include<iostream>
#include<vector>
#include<array>

struct node{
	std::array<int,2> c;
	int cnt;
};
std::vector<node> trie(1);

template<bool create>
auto findnode(std::string s /* consists of (char)0 and (char)1 */){
	int n=0;
	for(auto i=s.size();i--;){
		int& x=trie[n].c[s[i]];
		if(x==0){
			if(create){
				x=(int)trie.size();
				n=x;
				trie.push_back({}); // invalidates x
				continue;
			}else
				return -1;
		}
		n=x;
	}
	return n;
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::string s;
	while(n--){
		char type;std::cin>>type>>s;
		if(type=='?'){
			for(char& c:s)c=char(c-'0');
			s.erase(begin(s),std::find(begin(s),end(s),1));
			int x=findnode<false>(s);
			std::cout<<(x<0 ? 0 : trie[x].cnt)<<'\n';
		}else{
			for(char& c:s)c=char(c&1);
			s.erase(begin(s),std::find(begin(s),end(s),1));
			int x=findnode<true>(s);
			if(type=='+')
				++trie[x].cnt;
			else
				--trie[x].cnt;
		}
	}
}