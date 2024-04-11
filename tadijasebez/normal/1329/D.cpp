#include <bits/stdc++.h>
using namespace std;
const int N=200050;
char s[N];
int cnt[26],mx,all[N],sum;
int main(){
	int t;scanf("%i",&t);
	while(t--){
		scanf("%s",s+1);
		int n=strlen(s+1),pos=2;
		for(int i=1;i<=n;i++)s[i]-='a';
		for(int i=2;i<=n;i++)if(s[i]==s[i-1])sum++,cnt[s[i]]++;
		for(int i=0;i<26;i++)mx=max(mx,cnt[i]),all[cnt[i]]++;
		printf("%i\n",max(mx,(sum+1)/2)+1);
		stack<pair<int,char>> stk;
		for(int i=2;i<=n;i++,pos++){
			if(s[i]==s[i-1]){
				if(stk.size()&&s[i]!=stk.top().second&&(cnt[s[i]]==mx||cnt[stk.top().second]==mx||sum>2*mx)){
					printf("%i %i\n",stk.top().first,pos-1);
					pos=stk.top().first;
					sum-=2;
					all[cnt[s[i]]]--;cnt[s[i]]--;all[cnt[s[i]]]++;
					all[cnt[stk.top().second]]--;cnt[stk.top().second]--;all[cnt[stk.top().second]]++;
					if(!all[mx])mx--;
					stk.pop();
				}else stk.push({pos,s[i]});
			}
		}
		pos--;
		while(stk.size()){
			printf("%i %i\n",stk.top().first,pos);
			pos=stk.top().first-1;
			stk.pop();
		}
		printf("%i %i\n",1,pos);
		for(int i=0;i<26;i++)all[cnt[i]]--,cnt[i]=0;
		mx=sum=0;
	}
	return 0;
}