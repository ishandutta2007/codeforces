#include<bits/stdc++.h>

int n,m;

int t;

std::string s;
inline bool qry(int i){
	std::cout<<i<<' '<<s<<std::endl;
	std::string res;
	std::cin>>res;
	return res=="yes";
}

int main(){
	scanf("%d%d",&n,&m);
	s.resize(m,'1');
	std::vector<int> V(n),U;
	std::iota(V.begin(),V.end(),1);
	while(t<m){
		U.clear();
		for(auto i:V){
			while(qry(i))
				U.pop_back(),s[--t]='1';
			if(t<m){
				s[t]='0',s[t++]=qry(i)+'0';
				U.push_back(i);
			}
		}
		for(int o=(int)U.size()-1;~o;o--) if(qry(U[o]))
			while((int)U.size()>o+1)
				U.pop_back(),s[--t]='1';
		std::swap(U,V);
	}
	std::cout<<"0 "+s<<std::endl;
}