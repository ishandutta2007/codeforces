#include<bits/stdc++.h>
using namespace std;
const int N=2e2+10;
int n,k,cnt[26],ans[N];
char s[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(cnt,0,sizeof cnt);
		cin>>n>>k>>(s+1);
		for(int i=1;i<=n;++i)cnt[s[i]-'a']++,ans[i]=0;
		for(int i=0;i<26&&1ll*i*k<n;++i){
			for(int o=1;o<=k&&o<=cnt[i];++o){
				ans[o]+=ans[o]==i;
			}
		}
		for(int i=1;i<=k;++i)putchar(ans[i]+'a');
		puts("");
	}
	return 0;
}