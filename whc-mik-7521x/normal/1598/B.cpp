#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int cnt[8],ct[8][8];
		memset(cnt,0,sizeof cnt);
		memset(ct,0,sizeof ct);
		for(int i=1;i<=n;i++){
			vector<int>date;
			for(int o=1;o<=5;o++){
				int x;
				scanf("%d",&x);
				if(x){
					cnt[o]++;
					for(int j=0;j<(int)date.size();j++){
						ct[o][date[j]]++;
						ct[date[j]][o]++;
					}
					date.push_back(o);
				}
			} 
		}
		int kk=n/2,pd=0;
		for(int i=1;i<=5;i++){
			for(int o=i+1;o<=5;o++){
				if(cnt[i]>=kk&&cnt[o]>=kk){
					if(cnt[i]+cnt[o]-ct[i][o]>=n){
						pd=1;
						puts("YES");
						break;
					}
				}
			}
			if(pd)break;
		}
		if(!pd)puts("NO");
	}
	return 0;
}