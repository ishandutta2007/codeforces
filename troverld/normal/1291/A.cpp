#include<bits/stdc++.h>
using namespace std;
int T,n;
char s[3010];
vector<int>v;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s),v.clear();
		for(int i=0;i<n;i++)if(((s[i]-'0')&1)&&v.size()<=1)v.push_back(i);
		if(v.size()<=1)puts("-1");
		else printf("%c%c\n",s[v[0]],s[v[1]]);
	}
	return 0;
}