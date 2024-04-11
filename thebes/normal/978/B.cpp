#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

string s;
int N, i, cnt, ans;

int main(){
	cin>>N>>s;
	for(char c : s){
		if(c=='x') cnt++;
		else{
			ans += max(0,cnt-2);
			cnt = 0;
		}
	}
	ans += max(0,cnt-2);
	printf("%d\n",ans);
	return 0;
}