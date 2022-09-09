#include <bits/stdc++.h>
using namespace std;
#define pb push_back
set<char> v={'a','e','i','o','u'};
bool vov(char c){return v.count(c);}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<string> all(n);
	for(auto &i:all)cin>>i;
	map<pair<int,char>,string> str;
	vector<pair<string,string>> eds,sts;
	for(auto s:all){
		int cnt=0;
		char las;
		for(char c:s)
			if(vov(c))
				cnt++,
				las=c;
		if(str.count({cnt,las})){
			eds.pb({str[{cnt,las}],s});
			str.erase({cnt,las});
		}else str[{cnt,las}]=s;
	}
	map<int,string> mps;
	for(auto it:str){
		string s=it.second;
		int cnt=it.first.first;
		if(mps.count(cnt)){
			sts.pb({mps[cnt],s});
			mps.erase(cnt);
		}else mps[cnt]=s;
	}
	while(eds.size()>sts.size())sts.pb(eds.back()),eds.pop_back();
	while(sts.size()>eds.size())sts.pop_back();
	cout<<eds.size()<<"\n";
	for(int i=0;i<eds.size();i++){
		cout<<sts[i].first<<" "<<eds[i].first<<"\n";
		cout<<sts[i].second<<" "<<eds[i].second<<"\n";
	}
	return 0;
}