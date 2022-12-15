#include <bits/stdc++.h>
using namespace std;

string s; int st, cnt, i, j, ans, flag;

int main(){
	cin >> s;
	for(i=0;i<s.size();i++){
		st = cnt = flag = 0;
		for(j=i;j<s.size();j++){
			if(s[j]=='(') st++;
			else if(s[j]=='?'){
				if(st) st--, cnt++;
				else st++;
			}
			else{
				if(st==0&&cnt==0){flag=1; break;}
				else if(st==0) cnt--,st++;
				else st--;
			}
			if(st==0) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}