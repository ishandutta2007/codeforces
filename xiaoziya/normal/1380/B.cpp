#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int cnt[3];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s,n=s.size();
		for(int i=0;i<n;i++)
			cnt[s[i]=='R'? 0:(s[i]=='S'? 1:2)]++;
		int mx=max(cnt[0],max(cnt[1],cnt[2]));
		for(int i=0;i<n;i++)
			putchar((cnt[0]==mx)? 'P':(cnt[1]==mx? 'R':'S'));
		puts("");
		cnt[0]=cnt[1]=cnt[2]=0;
	}
	return 0;
}