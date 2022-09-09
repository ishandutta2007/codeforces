#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int mod=1e9+7;
int add(int a, int b){ a+=b;return a>=mod?a-mod:a;}
void ckadd(int &a, int b){ a=add(a,b);}
int sub(int a, int b){ a-=b;return a<0?a+mod:a;}
void cksub(int &a, int b){ a=sub(a,b);}
int mul(int a, int b){ return (ll)a*b%mod;}
void ckmul(int &a, int b){ a=mul(a,b);}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,ckmul(x,x)) if(k&1) ckmul(ans,x);return ans;}
int inv(int x){ return powmod(x,mod-2);}
const int N=5050;
vector<int> cows[N];
int cnt[N][N],all[N],now[N];
pair<int,int> Ways(int col,int l,int n){
	int ans=0;
	for(int x:cows[col]){
		if(x<=l){
			ckadd(ans,cnt[col][n-l]);
			if(x<=n-l)cksub(ans,1);
		}
	}
	if(ans>0)return {2,ans};
	ans=add(cnt[col][l],cnt[col][n-l]);
	if(ans>0)return {1,ans};
	return {0,1};
}
int s[N];
pair<int,int> dp[N];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)scanf("%i",&s[i]),all[s[i]]++;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%i %i",&x,&y);
		cnt[x][y]++;
		cows[x].pb(y);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cnt[i][j]+=cnt[i][j-1];
	int mx_ans=0,ways=0;
	for(int i=0;i<=n;i++){
		if(i>0)now[s[i]]++;
		int sum=0,ws=1;
		for(int j=1;j<=n;j++){
			if(j==s[i]){
				dp[i]=Ways(j,now[j],all[j]);
				pair<int,int> tmp=Ways(j,now[j]-1,all[j]-1);
				if(tmp.first==dp[i].first)cksub(dp[i].second,tmp.second);
			}else{
				dp[i]=Ways(j,now[j],all[j]);
			}
			sum+=dp[i].first;
			ckmul(ws,dp[i].second);
		}
		//printf("%i %i %i\n",i,sum,ws);
		if(sum>mx_ans)mx_ans=sum,ways=0;
		if(sum==mx_ans)ckadd(ways,ws);
	}
	printf("%i %i\n",mx_ans,ways);
	return 0;
}