#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	std::string s;
	while(ntest--){
		int x;
		std::cin>>x>>s;
		s.reserve(x);
		int slen=s.size();
		if((int)s.size()>x)s.resize(x);
		for(int l=1;l<=x;++l){
			int const MOD=1000000007;
			int nrep=s[l-1]-'0';
			assert(nrep>0 and nrep<=3);

			auto const old_size=(int)s.size();
			for(int i=nrep;--i;){
				assert((int)s.size()<=x);
				auto tmp=l+ x-(int)s.size() ;
				for(int j=l,end=std::min((int)old_size,l+ x-(int)s.size() );j<end;++j){
					s+=s[j];
					assert((int)s.size()<=x);
				}
				if((int)old_size >= tmp)
					assert((int)s.size()==x);
				if((int)s.size()==x)
					break;
			}

			slen=(slen+int64_t(slen-l+MOD)*(nrep-1))%MOD;
		}

		std::cout<<slen<<'\n';
	}
}