#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int pre[30][200005],cnt[30];
int check(int x){
	for(int i=0;i<26;i++){
		if(cnt[i]>pre[i][x])
			return false;
	}
	return true;
}
int main(){
	cin>>n>>s;
	s=" "+s;
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<26;j++){
			if(j==s[i]-'a')
				pre[j][i]=pre[j][i-1]+1;
			else
				pre[j][i]=pre[j][i-1];
		}
	}
	cin>>m;
	while(m--){
		string x;
		cin>>x;
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<x.size();i++){
			cnt[x[i]-'a']++;
		}
		int l=1,r=s.size(),ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))	r=mid-1,ans=mid;
			else			l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
8 
abcaecab
6
abcc
e
bb
aaa
aabbc
a
*/