#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

string s;
int i, j, res, x, cnt, ans=1<<30, w;

int main(){
	cin >> s;
	for(i=1;i<(1<<s.size());i++){
		for(w=cnt=res=j=0;j<s.size();j++){
			if((1<<j)&i){
				if(res==0&&s[j]=='0'){w=1; break;}
				res=res*10+s[j]-'0',cnt++;
			}
		}
		if(w) continue;
		cnt = s.size()-cnt;
		x = sqrt(res+0.0);
		if(cnt<ans&&x*x==res)
			ans = cnt;
	}
	printf("%d\n",(ans==1<<30)?-1:ans);
	return 0;
}