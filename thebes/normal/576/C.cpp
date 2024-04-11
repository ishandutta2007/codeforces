#include <bits/stdc++.h>
using namespace std;

const int MN=1e6+6,SZ=1010;
int n, i, x, y, p; vector<pair<int,int>> vec[SZ];
bool cmp1(pair<int,int>i,pair<int,int>j){return i.first<j.first;}
bool cmp2(pair<int,int>i,pair<int,int>j){return i.first>j.first;}

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		vec[x/SZ].push_back({y,i});
	}
	for(i=0;i<SZ;i++){
		if(vec[i].size()){
			if(!p) sort(vec[i].begin(),vec[i].end(),cmp1);
			else sort(vec[i].begin(),vec[i].end(),cmp2);
			p = !p;
			for(auto v : vec[i])
				printf("%d ",v.second);
		}
	}
	return 0;
}