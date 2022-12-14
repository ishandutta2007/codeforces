// n sqrt n log n...?
// cnt <= sqrt n OR len/cnt <= sqrt n
// ^ isn't this trivial and is standard for all square root decomposition? Why did I take so long to solve it?
//
// Had to write a brute force program.

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;
	for(char& c:s)c-='0';

	int const MAXSMALLQUOT=400; // TODO

	int64_t out=0;

	{
		std::vector<int64_t> v(s.size()+1); // len-cnt*quot values
		for(int quot=1;quot<=MAXSMALLQUOT;++quot){
			v[0]=0;
			for(unsigned i=1;i<=s.size();++i)
				v[i]=v[i-1]+1-quot*s[i-1];
			std::sort(begin(v),end(v));
			for(unsigned lastend=0,i=1;i<=v.size();++i){
				if(i==v.size() or v[i]!=v[i-1]){
					out+=int64_t(i-lastend)*(i-lastend-1)/2;
					lastend=i;
				}
			}
		}
	}

	std::vector<int> pos1;
	pos1.push_back(-1);
	for(int i=0;i<(int)s.size();++i)
		if(s[i])
			pos1.push_back(i);
	pos1.push_back(int(s.size()));

	for(int cnt=1;cnt*(MAXSMALLQUOT+1ULL)<=s.size() and cnt<=(int)pos1.size();++cnt){
		for(unsigned ix=1;ix+cnt<pos1.size();++ix){
			// there are cnt ones in [ix..ix+cnt[
			int const gapl=pos1[ix]-pos1[ix-1]-1;
			int const gapr=pos1[ix+cnt]-pos1[ix+cnt-1]-1;
			int const inlen=pos1[ix+cnt-1]-pos1[ix]+1;

			assert(gapl>=0);
			assert(gapr>=0);

			for(int len=cnt*(MAXSMALLQUOT+1);len<=int(s.size());len+=cnt){
				int const outlen=len-inlen;
				if(outlen<0)continue; // TODO

				int llen_min=std::max(0,outlen-gapr);
				int llen_max=std::min(gapl,outlen);
				if(llen_min>llen_max)break; // TODO (insignificant)

				out+=llen_max-llen_min+1;
			}
		}
	} // total complexity: number of (cnt, len) pair * pos1.size()
	std::cout<<out<<'\n';
}