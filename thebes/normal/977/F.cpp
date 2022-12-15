#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
map<int,int> coord; vector<int> chain[MN];
struct pq{bool operator()(const int&i,const int&j){return chain[i].size()<chain[j].size();}};
priority_queue<int,vector<int>,pq> id[MN];
int N, i, x, arr[MN], wts, ans, iD, rev[MN];

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d",&arr[i]);
		coord[arr[i]]=0;
	}
	auto it=coord.begin(); i=0; 
	for(;it!=coord.end();it++) it->second=++i, rev[i]=it->first;
	for(i=1;i<=N;i++){
		x = coord[arr[i]];
		int temp = 0;
		if(id[x].size()){
			temp = id[x].top(); id[x].pop();
			chain[temp].push_back(i);
		}
		else{
			chain[++iD].push_back(i);
			temp = iD;
		}
		if(rev[x+1]-rev[x]==1) id[x+1].push(temp);
		if(chain[temp].size()>ans) ans=chain[temp].size(),wts=temp;
	}
	printf("%d\n",ans);
	for(auto v : chain[wts]) printf("%d ",v);
	getchar(); getchar();
	return 0;
}