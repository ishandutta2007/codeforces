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
const ll inf=4e18;
const int N=1050;
ll dp[N][N],tmp[N],add[N][N];
string s;
int id[N][N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	ll k;
	//scanf("%i %i %lld",&n,&m,&k);
	cin>>n>>m>>k;
	cin>>s;

	/*mt19937 rng(time(0));
	n=1000;
	m=1000;
	k=(ll)rng()*rng();
	s="";
	for(int i=1;i<=n;i++)s+=('a'+(rng()%26));*/


	vector<pair<string,int>> all;
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)all.pb({s.substr(i-1,j-i+1),i*N+j});
	sort(all.begin(),all.end());
	for(int i=0;i<all.size();i++)id[all[i].second/N][all[i].second%N]=i+1;
	int bot=1,top=all.size(),mid,ans=all.size();
	while(top>=bot){
		mid=top+bot>>1;
		for(int i=0;i<m;i++)tmp[i]=0;
		for(int i=1;i<=n;i++)for(int j=0;j<m;j++)add[i][j]=0;
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			int z;
			for(z=i;z<=n && id[i][z]<mid;z++);
			if(z<=n)for(int j=0;j<m;j++){
				add[z][j]+=dp[i-1][j];
				add[z][j]=min(add[z][j],inf);
			}
			for(int j=0;j<m;j++){
				tmp[j]+=add[i][j];
				tmp[j]=min(tmp[j],inf);
				dp[i][j+1]=tmp[j];
			}
			//dp[i]=0;
			//for(int j=i;j>=1;j--)
			//	if(id[j][i]>=mid)
			//		dp[i]+=dp[j];
		}
		ll ways=dp[n][m];
		//printf("%i %lld\n",mid,ways);
		if(ways>=k)ans=mid,bot=mid+1;
		else top=mid-1;
	}
	cout<<all[ans-1].first<<"\n";
	//for(auto t:all)cout<<t.first<<"\n";
	return 0;
}