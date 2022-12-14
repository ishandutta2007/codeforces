#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;

	std::array<std::vector<int>,26> sfxsum;
	for(int ch=0;ch<26;++ch){
		sfxsum[ch].resize(s.size()+1);
		for(auto idx=s.size();idx--;)
			sfxsum[ch][idx]=sfxsum[ch][idx+1]+(s[idx]=='a'+ch);
	}

	int nquery;std::cin>>nquery;
	while(nquery--){
		int l,r;std::cin>>l>>r;--l;
		if(r-l==1){
yes:
			std::cout<<"Yes\n";
			continue;
		}
		int nch=0;
		for(int ch=0;ch<26;++ch)
			nch+=sfxsum[ch][l]-sfxsum[ch][r]!=0;

		if(nch==1 or (nch==2 and s[l]==s[r-1])){
			std::cout<<"No\n";
			continue;
		}

		goto yes;
	}
}