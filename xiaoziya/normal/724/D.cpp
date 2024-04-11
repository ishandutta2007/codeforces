#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int cnt[maxn],vis[maxn];
string s;
int main(){
	scanf("%d",&n),cin>>s,s=" "+s;
	for(int i=1;i<s.size();i++)
		cnt[s[i]-96]++;
	for(int i=1;i<=26;i++)
		if(cnt[i]){
			int lst=0,flg=0;
			vector<int>v;
			for(int j=1;j<s.size();j++){
				if(vis[j])
					lst=j;
				if(s[j]==i+96)
					v.push_back(j),vis[j]=1;
				if(j-lst>=n){
					if(!v.empty()&&j-v.back()<n)
						lst=v.back(),v.pop_back(),putchar(i+96);
					else flg=1;
				}
			}
			if(flg==0)
				return 0;
			while(!v.empty())
				v.pop_back(),putchar(i+96);
		}
	return 0;
}