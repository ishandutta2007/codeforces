#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int L=18;
vector<int> masks[L+1];
ll dp[1<<L][L],ans[1<<L];
int E[L],len[L],bl,n,lg[1<<L];
void upd(int cnt,bool same){
	for(int i=0;i<n;++i){
		for(int mask:masks[cnt+1]){
			dp[mask][i]=0;
			if(mask>>i&1){
				int sub=mask^(1<<i);
				if(same)sub&=E[i];
				for(;sub;sub-=sub&-sub){
					int j=lg[sub&-sub];
					dp[mask][i]+=dp[mask^(1<<i)][j];
				}
			}
		}
	}
}
void DFS(int cnt){
	if(cnt==n){
		vector<int> ls;
		for(int i=bl-1;~i;--i)ls.pb(len[i]);
		ll sol=0;
		for(int i=0;i<n;++i)sol+=dp[(1<<n)-1][i];
		do{
			int num=0;
			for(int sz:ls){num*=2;for(;--sz;)num=num*2+1;}
			ans[num]=sol;
		}while(next_permutation(ls.begin(),ls.end()));
	}else{
		if(bl==1 || len[bl-2]>len[bl-1]){
			len[bl-1]++;
			upd(cnt,1);
			DFS(cnt+1);
			len[bl-1]--;
		}
		bl++;
		len[bl-1]=1;
		upd(cnt,0);
		DFS(cnt+1);
		bl--;
	}
}
int main(){
	scanf("%i",&n);
	for(int i=0;i<n;++i){
		char s[20];scanf("%s",s);
		for(int j=0;j<n;j++)
			if(s[j]=='1')
				E[i]+=1<<j;
	}
	for(int i=0;i<1<<n;++i)masks[__builtin_popcount(i)].pb(i);
	len[0]=1;bl=1;
	for(int i=0;i<n;++i)dp[1<<i][i]=1,lg[1<<i]=i;
	DFS(1);
	for(int i=0;i<n;++i)for(int mask=0;mask<1<<(n-1);++mask)if(!(mask>>i&1))ans[mask]-=ans[mask^(1<<i)];
	for(int mask=0;mask<1<<(n-1);++mask)printf("%lld ",ans[mask]);
	return 0;
}