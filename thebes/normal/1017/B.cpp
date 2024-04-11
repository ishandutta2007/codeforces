#include <bits/stdc++.h>
using namespace std;

map<int,int> cnt;
long long ans, N, i;
string s, t;

int main(){
	cin >> N >> s >> t;
	for(i=0;i<s.size();i++){
		int msk = (s[i]-'0')*2+(t[i]-'0');
		if(msk&1) ans+=cnt[(~msk)&3];
		else ans+=cnt[(~msk)&3]+cnt[((~msk)^1)&3];
		cnt[msk]++;
	}
	printf("%lld\n",ans);
	return 0;
}