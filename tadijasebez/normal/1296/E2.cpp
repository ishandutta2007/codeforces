#include <bits/stdc++.h>
using namespace std;
const int N=200050;
char s[N];
int col[N];
int main(){
	int n;
	scanf("%i %s",&n,s+1);
	set<pair<char,int>> all;
	for(int i=n;i>=1;i--){
		auto it=all.lower_bound({s[i],0});
		if(it==all.end()){
			col[i]=all.size()+1;
			all.insert({s[i],col[i]});
		}else{
			col[i]=it->second;
			all.erase(it);
			all.insert({s[i],col[i]});
		}
	}
	printf("%i\n",all.size());
	for(int i=1;i<=n;i++)printf("%i ",col[i]);
	return 0;
}