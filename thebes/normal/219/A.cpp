#include <bits/stdc++.h>
using namespace std;

string s, out; bool a=1;
int cnt[26], k, i;

int main(){
	cin >> k >> s;
	for(i=0;i<(signed)s.size();i++)
		cnt[s[i]-'a']++;
	for(i=0;i<26;i++)
		a=min(a,!(cnt[i]%k));
	if(!a) printf("-1\n");
	else{
		for(i=0;i<26;i++){
			while(cnt[i] > 0){
				out.push_back(i+'a');
				cnt[i] -= k;
			}
		}
		for(i=0;i<k;i++) printf("%s",out.c_str());
	}
	return 0;
}