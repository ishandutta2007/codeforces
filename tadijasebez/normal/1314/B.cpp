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
const int N=1<<20;
int dp1[N],dp2[N],dp3[N],mdp[N];
int cnt[N],a[N],ob[N],sz[N];
void Solve(int id,int ss,int se){
	if(ss==se){
		sz[id]=cnt[ss];
		if(sz[id]>1)dp3[id]=3;
		if(sz[id]>0)dp1[id]=1,dp2[id]=2;
	}else{
		int mid=ss+se>>1;
		Solve(id*2,ss,mid);
		Solve(id*2+1,mid+1,se);
		sz[id]=sz[id*2]+sz[id*2+1];
		if(sz[id]>0)dp1[id]=dp1[id*2]+dp1[id*2+1]+1;
		if(sz[id]>0)dp2[id]=dp2[id*2]+dp2[id*2+1]+2;
		if(sz[id]>1){
			if(sz[id*2  ]>1)ckmx(dp3[id],dp3[id*2]+mdp[id*2+1]+3);
			if(sz[id*2+1]>1)ckmx(dp3[id],mdp[id*2]+dp3[id*2+1]+3);
			if(sz[id*2]>0 && sz[id*2+1]>0){
				ckmx(dp3[id],dp1[id*2]+dp2[id*2+1]+3);
				ckmx(dp3[id],dp2[id*2]+dp1[id*2+1]+3);
			}
		}
	}
	mdp[id]=max({dp1[id],dp2[id],dp3[id]});
	//printf("%i (%i %i): %i %i %i\n",id,ss,se,dp1[id],dp2[id],dp3[id]);
}
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	for(int i=1;i<=k;i++)scanf("%i",&a[i]),cnt[(a[i]+3)/4]++,ob[(a[i]+1)/2]++;
	Solve(1,1,1<<(n-2));
	int ans=mdp[1];
	if(k>0)ans++;
	for(int i=0;i<N;i++)if(ob[i]>0)ans++;
	printf("%i\n",ans);
	return 0;
}