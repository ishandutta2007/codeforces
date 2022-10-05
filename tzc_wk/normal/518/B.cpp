#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[200005],t[200005];
map<char,int> cnt;
bool vis[200005];
int ans1=0,ans2=0;
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s",t+1);m=strlen(t+1);
	cnt.clear();
	for(int i=1;i<=m;i++)	cnt[t[i]]++;
	for(int i=1;i<=n;i++)
		if(cnt[s[i]]){
			ans1++;
			vis[i]=1;
			cnt[s[i]]--;
		}
	for(int i=1;i<=n;i++){
        if(!vis[i])
			if(cnt[s[i]-'a'+'A']){ans2++;cnt[s[i]-'a'+'A']--;}
		else
			if(cnt[s[i]-'A'+'a']){ans2++;cnt[s[i]-'A'+'a']--;}
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}