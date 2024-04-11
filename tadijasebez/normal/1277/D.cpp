#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cnt[2]={0,0},can[2]={0,0};
		vector<int> cng[2];
		vector<string> str(n);
		set<string> has;
		bool onl[2]={0,0};
		for(auto &i:str)cin>>i,has.insert(i);
		for(int i=0;i<n;i++){
			string tmp=str[i];
			if(tmp.front()!=tmp.back()){
				cnt[tmp.front()-'0']++;
				reverse(tmp.begin(),tmp.end());
				if(!has.count(tmp)){
					can[tmp.back()-'0']++;
					cng[tmp.back()-'0'].pb(i+1);
				}
			}else onl[tmp.front()-'0']=1;
		}
		if(cnt[0]>cnt[1])
			swap(cnt[0],cnt[1]),
			swap(can[0],can[1]),
			swap(cng[0],cng[1]);
		vector<int> ans;
		while(cnt[0]+1<cnt[1]){
			if(can[1]==0)break;
			cnt[0]++;
			cnt[1]--;
			can[1]--;
			ans.pb(cng[1].back());
			cng[1].pop_back();
		}
		if(cnt[0]+cnt[1]==0){
			if(onl[0] && onl[1])printf("-1\n");
			else printf("0\n\n");
		}
		else if(cnt[0]+1<cnt[1])printf("-1\n");
		else{
			printf("%i\n",ans.size());
			sort(ans.begin(),ans.end());
			for(int i:ans)printf("%i ",i);
			printf("\n");
		}
	}
	return 0;
}