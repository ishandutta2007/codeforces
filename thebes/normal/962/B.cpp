#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
string s; int N, i, a, b, cnt, pre;

int main(){
	cin>>N>>a>>b>>s;
	for(i=0;i<s.size();i++){
		if((!i&&s[i]=='.')||(s[i]=='.'&&s[i-1]=='*')){
			if(a>b) a--,cnt++,pre=0;
			else b--,cnt++,pre=1;
		}
		else if(s[i]=='.'&&s[i-1]=='.'){
			if(pre==0) b--,cnt++,pre=1;
			else a--,cnt++,pre=0;
		}
	}
	printf("%d\n",cnt-max(-a,0)-max(-b,0));
	return 0;
}