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
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ldb double
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
const int N=300050;
int my[N],cmp[N],mora[N],ans,cnt[N][2];
vector<int> skup[N],xb[N];
void Del(int c){
	if(~mora[c])ans-=cnt[c][mora[c]];
	else ans-=min(cnt[c][0],cnt[c][1]);
}
void Add(int c){
	if(~mora[c])ans+=cnt[c][mora[c]];
	else ans+=min(cnt[c][0],cnt[c][1]);
}
char s[N];
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	for(int i=1;i<=k;i++)skup[i].pb(i),my[i]=0,cmp[i]=i,mora[i]=-1,cnt[i][0]=1;
	scanf("%s",s+1);
	for(int i=1;i<=k;i++){
		int sz;
		scanf("%i",&sz);
		while(sz--){
			int x;
			scanf("%i",&x);
			xb[x].pb(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(xb[i].size()==1){
			int x=xb[i][0];
			if(s[i]=='0'){
				Del(cmp[x]);
				mora[cmp[x]]=my[x];
				//printf("mora: %i %i %i\n",mora[cmp[x]],cnt[cmp[x]][0],cnt[cmp[x]][1]);
				Add(cmp[x]);
			}else{
				Del(cmp[x]);
				mora[cmp[x]]=my[x]^1;
				//printf("mora: %i %i %i\n",mora[cmp[x]],cnt[cmp[x]][0],cnt[cmp[x]][1]);
				Add(cmp[x]);
			}
		}else if(xb[i].size()==2){
			int w=s[i]=='0';
			int x=xb[i][0],y=xb[i][1];
			if(cmp[x]!=cmp[y]){
				if(skup[cmp[x]].size()>skup[cmp[y]].size())swap(x,y);
				Del(cmp[x]);
				Del(cmp[y]);
				if(my[x]!=(my[y]^w)){
					swap(cnt[cmp[x]][0],cnt[cmp[x]][1]);
					if(~mora[cmp[x]])mora[cmp[x]]^=1;
					for(int lu:skup[cmp[x]]){
						my[lu]^=1;
					}
				}
				if(~mora[cmp[x]])mora[cmp[y]]=mora[cmp[x]];
				int xc=cmp[x];
				for(int lu:skup[xc]){
					skup[cmp[y]].pb(lu);
					cmp[lu]=cmp[y];
					cnt[cmp[y]][my[lu]]++;
				}
				skup[xc].clear();
				Add(cmp[y]);
			}
		}
		printf("%i\n",ans);
		//for(int j=1;j<=k;j++)if(skup[j].size()){
		//	printf("|%i %i %i| ",mora[j],cnt[j][0],cnt[j][1]);
		//	for(int lu:skup[j])printf("(%i %i %i) ",cmp[lu],my[lu],lu);
		//	printf("\n");
		//}
	}
	return 0;
}