#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
char s[N],t[N];
int cnt[30][30];
void solve(){
	scanf("%d%s%s",&n,s+1,t+1);
	reverse(t+1,t+n+1);
	for(int i=1;i<=n;i++){
		if(s[i]>t[i])swap(s[i],t[i]);
		cnt[s[i]-'a'][t[i]-'a']++;
	}
	int c=0;
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++){
			if(cnt[i][j]&1)c+=1+(i!=j);
			cnt[i][j]=0;
		}
	puts(c<=1?"YES":"NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}