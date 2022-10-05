#include <bits/stdc++.h>
using namespace std;
int k;
long long cnt[26],sumcnt[26];
vector<int> cur;
string s;
int main(){
	cin>>s>>k;
	for(int i=0;i<s.size();i++){
		cur.push_back(i);
	}
	if(k>(long long)(s.size())*(s.size()+1)/2){
		cout<<"No such line.\n";
		return 0;
	}
	string res="";
	--k;
	for(;;){
		memset(cnt,0,sizeof(cnt));
		memset(sumcnt,0,sizeof(sumcnt));
		for(int i=0;i<cur.size();i++){
			cnt[s[cur[i]]-'a']++;
			sumcnt[s[cur[i]]-'a']+=s.size()-cur[i];
		}
		int ch=0;
		while(ch<26&&sumcnt[ch]<=k){
			k-=sumcnt[ch];
			ch++;
		}
		if(ch>=26){
			cout<<"No such line.\n";
			return 0;
		}
		res+='a'+ch;
		if(k<cnt[ch])	break;
		k-=cnt[ch];
		vector<int> now;
		for(int i=0;i<cur.size();i++){
			if(s[cur[i]]-'a'==ch&&cur[i]+1<s.size())
				now.push_back(cur[i]+1);
		}
		cur.swap(now);
	}
	printf("%s",res.c_str());
}