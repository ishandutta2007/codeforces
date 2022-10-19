#include <bits/stdc++.h>
using namespace std;
int n,k;
map<char,int> ans;
string s;
int main(){
	cin>>n>>k>>s;
	for(int i=0;i<s.size();){
		bool cantravel=true;
		int diff;
		for(int j=i;j<i+k;j++){
			if(s[j]!=s[i]){
				diff=j;
				cantravel=false;
				break;
			}
		}
		if(cantravel)	ans[s[i]]++,i+=k;
		else	i=diff;
	}
	int RES=0;
	for(char c='a';c<='z';c++){
		RES=max(RES,ans[c]);
	}
	cout<<RES<<endl;
}