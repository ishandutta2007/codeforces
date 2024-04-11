#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	auto gt=[&](char a,char b){
		if(a!='S' && b!='S')return 'S';
		if(a!='E' && b!='E')return 'E';
		if(a!='T' && b!='T')return 'T';
	};
	auto comb=[&](string a,string b){
		string ans="";
		for(int i=0;i<k;i++){
			if(a[i]==b[i])ans+=a[i];
			else ans+=gt(a[i],b[i]);
		}
		return ans;
	};
	vector<string> str(n);
	unordered_map<string,int> cnt;
	for(int i=0;i<n;i++)cin>>str[i],cnt[str[i]]++;
	long long ans=0;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j){
		cnt[str[i]]--;
		cnt[str[j]]--;
		ans+=cnt[comb(str[i],str[j])];
		cnt[str[i]]++;
		cnt[str[j]]++;
	}
	printf("%lld\n",ans/6);
	return 0;
}