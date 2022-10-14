#include <bits/stdc++.h>
using namespace std;
int main(){
	int tt;
	scanf("%i",&tt);
	while(tt--){
		int n,m;
		scanf("%i%i",&n,&m);
		vector<vector<int>> a(n,vector<int>(m));
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%i",&a[i][j]);
		auto Check=[&](int x){
			vector<int> have(m);
			bool ok=false;
			for(int i=0;i<n;i++){
				int cnt=0;
				for(int j=0;j<m;j++){
					if(a[i][j]>=x)cnt++,have[j]|=1;
				}
				ok|=(cnt>1);
			}
			for(int i=0;i<m;i++)ok&=(have[i]==1);
			return ok;
		};
		int bot=0,top=1e9,ans=0;
		while(bot<=top){
			int mid=bot+top>>1;
			if(Check(mid))ans=mid,bot=mid+1;
			else top=mid-1;
		}
		printf("%i\n",ans);
	}
	return 0;
}