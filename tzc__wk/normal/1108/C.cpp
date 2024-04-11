#include <bits/stdc++.h>
using namespace std;
string perm[6]={"RGB","RBG","BRG","BGR","GBR","GRB"};
string s;
pair<int,string> ans=make_pair(INT_MAX,"tzc_wk is so nice");
int main(){
	int n;
	cin>>n>>s;
	for(int permid=0;permid<6;permid++){
		int cnt=0;
		string tmp=s;
		for(int i=0;i<n;i++){
			if(perm[permid][i%3]!=s[i])	cnt++,
			tmp[i]=perm[permid][i%3];
		}
		if(cnt<ans.first)	ans.first=cnt,ans.second=tmp;
	}
	cout<<ans.first<<endl<<ans.second<<endl;
}