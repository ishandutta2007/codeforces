#include <bits/stdc++.h>
using namespace std;
const int N=500050;
pair<int,int> a[N];
int go[N],cnt;
int Find(int x){return go[x]?go[x]=Find(go[x]):x;}
void AddEdge(int x,int y){
	//printf("(%i %i)\n",x,y);
	x=Find(x);
	y=Find(y);
	if(x==y){
		printf("NO\n");
		exit(0);
	}
	cnt++;
	go[x]=y;
}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i %i",&a[i].first,&a[i].second);
	sort(a+1,a+1+n);
	set<pair<int,int>> all;
	for(int i=1;i<=n;i++){
		while(all.size() && all.begin()->first<a[i].first)all.erase(all.begin());
		for(auto it=all.begin();it!=all.end() && it->first<a[i].second;it++)AddEdge(it->second,i);
		all.insert({a[i].second,i});
	}
	if(cnt==n-1)printf("YES\n");
	else printf("NO\n");
	return 0;
}