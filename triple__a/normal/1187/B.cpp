#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int n;
vector<int> p[30];
char s[maxn];


int main(){
	cin>>n>>s;
	for (int i=0;i<30;++i){
		p[i].clear();
	}
	for (int i=0;i<n;++i){
		p[s[i]-'a'].push_back(i);
	}
	int m;
	cin>>m;
	while(m--){
		char tmp[maxn];
		cin>>tmp;
		int t[28],l=strlen(tmp);
		memset(t,0,sizeof(t));
		for (int i=0;i<l;++i){
			t[tmp[i]-'a']++;
		}
		int ans=0;
		for (int i=0;i<26;++i){
			if (t[i]){
				ans=max(ans,p[i][t[i]-1]);
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}