#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;

	std::vector<int> cnto(s.size()+1),cntc(s.size()+1),cntq(s.size()+1);
	for(auto i=s.size();i--;){
		cnto[i]=cnto[i+1]+(s[i]=='(');
		cntc[i]=cntc[i+1]+(s[i]==')');
		cntq[i]=cntq[i+1]+(s[i]=='?');
	}

	std::vector<int> dpl(s.size()+1);
	std::vector<int> dpr(s.size()+1);
	// dpr[r]: min l s.t. s[l..r] with '?' replaced with '(' is a suffix of any correct bracket seq
	// dpl[l]: max r s.t. s[l..r] with '?' replaced with ')' is a prefix of any correct bracket seq
	
	for(int r=1;r<=(int)s.size();++r){
		int l=r,deglr=0;
		for(;;){
			--l;
			if(l<0) break;
			deglr+=s[l]=='(' ? -1 : 1;
			if(deglr<0) break;
		}
		dpr[r]=l+1;
	}

	for(int l=0;l<(int)s.size();++l){
		int r=l,deglr=0;
		for(;;){
			++r;
			if(r>(int)s.size()) break;
			deglr+=s[r-1]==')' ? -1 : 1;
			if(deglr<0) break;
		}
		dpl[l]=r-1;
	}

	std::vector<int> prevq(s.size()+1);
	std::vector<int> nextq(s.size());
	for(int previ=-1,i=0;;++i){
		prevq[i]=previ;
		if(i==(int)s.size()) break;
		if(s[i]=='?') previ=i;
	}
	for(int nexti=(int)s.size(),i=(int)s.size();i--;){
		nextq[i]=nexti;
		if(s[i]=='?') nexti=i;
	}

	int out=0;
	auto const process=[&](int l,int r){
		assert(std::cerr<<l<<' '<<r<<'\n');
		++out;
	};
	for(int r=1;r<=(int)s.size();++r){
		int l=r;
		int deglr=0; // #( in l..r - #) in l..r == #? in mid..r - #? in l..mid
		int nqlr=0;
		int mid=r,nqmidr=0;
		for(;;){
			--l;
			if(l<0) break;
			
			switch(s[l]){
				case '?':
					++nqlr; break;
				case '(':
					++deglr; break;
				case ')':
					--deglr; break;
			}

			if((r-l)&1) continue;

			if(nqlr==0){
				if(dpl[l]>=r and deglr==0){
					assert(dpr[r]<=l);
					process(l,r);
					continue;
				}
			}
			if(dpl[l]<dpr[r]) continue;

			while(deglr>nqmidr-(nqlr-nqmidr)){
				if(prevq[mid]<l) goto lr_not_pretty;
				mid=prevq[mid];++nqmidr;
			}
			while(deglr<nqmidr-(nqlr-nqmidr)){
				if(mid==r){ assert(nqmidr==0); goto lr_not_pretty; }
				if(nextq[mid]>=r){ mid=r;nqmidr=0; }
				else { mid=nextq[mid];--nqmidr; }
			}

			assert(deglr==nqmidr-(nqlr-nqmidr));
			if(std::max(dpr[r],prevq[mid]+1)<=std::min(dpl[l],mid)) process(l,r);

lr_not_pretty:;
		}
	}
	std::cout<<out<<'\n';
}