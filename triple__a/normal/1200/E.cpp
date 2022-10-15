#include<bits/stdc++.h>
using namespace std;

int n;
string ans,word;

vector<int> get_pi(string s){
	int j=0,k=-1;
	vector<int> q;
	q.clear();
	q.push_back(-1);
	while (j<s.size()){
//		cout<<s<<" "<<j<<endl;
		if (k==-1||s[j]==s[k]){
			q.push_back(++k);
			++j;
		}
		else{
			k=q[k];
		}
	}
/*	for (int i=0;i<j;++i){
		cout<<q[i]<<" ";
	}
	cout<<endl;
*/
	return q;
}

int main(){
//	ios::sync_with_stdio(false);
	ans="";
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>word;
		int l=min(word.size(),ans.size());
		string s=word+"#";
		s.insert(s.end(),ans.end()-l,ans.end());
		vector<int> pi=get_pi(s);
		int move=pi[pi.size()-1];
		ans.insert(ans.end(),word.begin()+move,word.end());
	}
	cout<<ans<<endl;
	return 0;
}