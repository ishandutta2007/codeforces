#include<iostream>
#include<cassert>
#include<numeric>
#include<climits>
#include<algorithm>
#include<bitset>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(2*n);for(int& x:a)std::cin>>x;
	std::sort(begin(a),end(a));

	int constexpr ENDSUM=25*2*50000+1;

	std::vector<std::vector<std::bitset<ENDSUM>>> f(2*n+1); // f[i][c][s] = Is there a subset of a[i..] with size c and sum s?
	// 25*2*50000 (s) * 50 (i) * 25(c) = 3e9
	f[2*n].resize(1);f[2*n][0][0]=1;

	for(int i=2*n-1;i!=0;--i){
		f[i].resize(f[i+1].size()+1); // don't sacrifice code readability for small performance improvement
		for(unsigned c=0;c<f[i+1].size();++c)
			f[i][c]=f[i+1][c];
		for(unsigned c=0;c<f[i+1].size();++c)
			f[i][c+1]|=f[i+1][c]<<a[i];

		if(f[i].size()>n)
			f[i].resize(n);
	}

	int const T=std::accumulate(begin(a),end(a),0);
	// we should find a set S such that a[0] not in S, |S|=n, max(min S + T - sum(S), a[0] + sum(S)} is min

	int ans=INT_MAX,besti=-1,bestss=-1;
	for(int i=1;i<=n;++i){
		int const mins=a[i];
		auto const& z=f[i+1][n-1];

		for(int ss=0;ss<(int)z.size();++ss)if(z[ss]){
			int const sums=ss+mins;
			int newans=std::max(mins+T-sums,a[0]+sums);
			if(newans<ans){
				ans=newans;
				besti=i;
				bestss=ss;
			}
		}
	}

	std::vector<char> in_set_s(2*n);
	{
		in_set_s[besti]=true;
		int i=besti+1,ss=bestss,c=n-1;
		while(i<2*n&&c!=0){
			std::cerr<<i<<' '<<c<<' '<<ss<<'\n';
			assert(f.at(i).at(c)[ss]);
			assert(f.at(i+1).size()>=c);
			if(ss>=a[i]&&f[i+1][c-1][ss-a[i]]){
				in_set_s[i]=true;
				assert(f.at(i+1).size()>=c);
				assert(f.at(i+1).at(c-1)[ss-a[i]]);
				++i;
				assert(f.at(i).size()>=c);
				assert(f.at(i).at(c-1)[ss-a[i-1]]);
				--c;
				assert(f.at(i).size()>=c+1);
				assert(f.at(i).at(c)[ss-a[i-1]]);
				ss-=a[i-1];
				assert(f.at(i).size()>=c+1);
				assert(f.at(i).at(c)[ss]);
			}else{
				++i;
				assert(f.at(i).at(c)[ss]);
			}
		}
	}
	for(int i=0;i<2*n;++i)
		if(!in_set_s[i])
			std::cout<<a[i]<<' ';
	std::cout<<'\n';
	for(int i=2*n;i--;)
		if(in_set_s[i])
			std::cout<<a[i]<<' ';
	std::cout<<'\n';


}