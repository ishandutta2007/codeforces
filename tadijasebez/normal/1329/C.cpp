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
const int N=1<<22;
int a[N],h,g,mx[N];
bool take[N];
vector<int> DFS(int i=1,int dep=1){
	if(dep==h){
		take[i]=1;
		mx[i]=0;
		return {i};
	}
	vector<int> A=DFS(i*2,dep+1);
	vector<int>	B=DFS(i*2+1,dep+1);
	mx[i]=max(mx[i*2],mx[i*2+1]);
	if(dep>g){
		for(int j:B)A.pb(j);
		A.pb(i);
		take[i]=1;
		return A;
	}
	if(dep==g){
		for(int j:B)A.pb(j);
		sort(A.begin(),A.end(),[&](int x,int y){return a[x]>a[y];});
		take[A.back()]=0;A.pop_back();
		take[i]=1;A.pb(i);
		return A;
	}
	sort(A.begin(),A.end(),[&](int x,int y){return a[x]>a[y];});
	sort(B.begin(),B.end(),[&](int x,int y){return a[x]>a[y];});
	//if(a[A.back()]>a[B.back()])swap(A,B);
	while(A.size() && a[A.back()]<mx[i])A.pop_back();
	while(B.size() && a[B.back()]<mx[i])B.pop_back();
	//A.clear();
	if(A.empty() || (B.size() && a[A.back()]>a[B.back()]))swap(A,B);
	mx[i]=a[B.back()];
	take[B.back()]=0;B.pop_back();
	for(int j:B)A.pb(j);
	take[i]=1;A.pb(i);
	return A;
}
ll sum=0,all=0;
pair<int,int> tk(int i,int d){
	if(a[i*2]==0 && a[i*2+1]==0)return {i,d};
	if(a[i*2]>a[i*2+1])return tk(i*2,d+1);
	else return tk(i*2+1,d+1);
}
void pu(int i){
	if(a[i*2]==0 && a[i*2+1]==0)a[i]=0;
	else if(a[i*2]>a[i*2+1])a[i]=a[i*2],pu(i*2);
	else a[i]=a[i*2+1],pu(i*2+1);
}
vector<int> ans;
void Try(int i,int d){
	if(!a[i])return;
	while(1){
		pair<int,int> p=tk(i,d);
		if(p.second<=g)break;
		sum+=a[i];
		ans.pb(i);
		pu(i);
	}
	Try(i*2,d+1);
	Try(i*2+1,d+1);
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		scanf("%i %i",&h,&g);
		all=0;
		ans.clear();
        for(int i=1;i<1<<(h+1);i++)a[i]=0;
		for(int i=1;i<1<<h;i++)scanf("%i",&a[i]),all+=a[i],take[i]=0;
		sum=0;
		Try(1,1);
		printf("%lld\n",all-sum);
		for(int i:ans)printf("%i ",i);
		printf("\n");
		/*vector<int> ans=DFS(1,1);
		ll sum=0;
		for(int i=1;i<1<<h;i++)if(!take[i])sum+=a[i];
		sort(ans.begin(),ans.end());
		printf("%lld\n",sum);
		for(int i=(1<<h)-1;i>=1;i--)if(take[i])printf("%i ",i);
		printf("\n");*/
	}
	return 0;
}