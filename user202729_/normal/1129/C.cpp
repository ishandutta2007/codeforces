#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<unordered_set>

int64_t constexpr HASHMOD=63491840249341883LL;
// int constexpr BASE=2;
int constexpr ANSMOD=1000000007;

void hashadd(int64_t& a,int64_t b){
	a+=b;if(a>=HASHMOD)a-=HASHMOD;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	// subs[i] = set of hash values of seen substrings of s with length i
	std::vector<std::unordered_set<int64_t>> subs(n+1);
	for(int i=1;i<=n;++i){
		int maxsz=n-i+1;
		if(i<30)maxsz=std::min(maxsz,1<<i);
		subs[i].reserve(maxsz);
	}

	std::vector<int> dp;dp.reserve(n+1); // dp[l] = number of valid partitions of [l:r]

	std::vector<char> s;s.reserve(n);
	int ans=0;
	for(int r=1;r<=n;++r){
		{
			char c;std::cin>>c;s.push_back(c-'0');
		}
		dp.resize(r+1);
		dp[r]=1;

		int64_t hashlr=0,hashbase=1;
		for(int l=r;l-->0;){
			if(s[l])hashadd(hashlr,hashbase);
			hashadd(hashbase,hashbase);

			int64_t dpl=0;
			for(int i=1;i<=4;++i){
				if(l+i>r)break;
				if(i==4&&(
						(s[l]==0&&s[l+1]==0&&s[l+2]==1&&s[l+3]==1)||
						(s[l]==0&&s[l+1]==1&&s[l+2]==0&&s[l+3]==1)||
						(s[l]==1&&s[l+1]==1&&s[l+2]==1&&s[l+3]==0)||
						(s[l]==1&&s[l+1]==1&&s[l+2]==1&&s[l+3]==1)
						))
						break;
				dpl+=dp[l+i];
			}
			dp[l]=dpl%=ANSMOD;

			if(subs[r-l].insert(hashlr).second){
				ans=(ans+dpl)%ANSMOD;
			}
		}

		std::cout<<ans<<'\n';
	}
}