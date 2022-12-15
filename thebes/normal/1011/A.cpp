#include <bits/stdc++.h>
using namespace std;

int n, k, i, c, ans;
string s;

int main(){
	cin>>n>>k>>s;
	sort(s.begin(),s.end());
	c = s[0]; ans = s[0]-'a'+1;
	k--;
	for(char ch : s){
		if(!k) break;
		if(ch-c>=2){
			c = ch; ans+=ch-'a'+1;
			k--;
		}
	}
	if(k) printf("-1\n");
	else printf("%d\n",ans);
	getchar(); getchar();
}