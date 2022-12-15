#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> cnt;
int N; string s;

int main(){
	for(scanf("%d",&N);N>0;N--){
		cin >> s; cnt[s]++;
		if(cnt[s]!=1) printf("%s%s\n",s.c_str(),to_string(cnt[s]-1).c_str());
		else printf("OK\n");
	}
	return 0;
}