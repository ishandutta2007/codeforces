#include<bits/stdc++.h>
using namespace std;
int T,n,a[200100],b[200100];
set<int>s,t;
vector<int>v[200100];
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)v[i].clear();s.clear();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v[a[i]].push_back(i),s.insert(a[i]);
	while(!s.empty()){
		int p=*s.rbegin();
		for(auto x:s)b[v[x].back()]=p,p=x,v[x].pop_back();
		for(auto x:s)if(!v[x].empty())t.insert(x);
		s=t,t.clear();
	}
	for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}