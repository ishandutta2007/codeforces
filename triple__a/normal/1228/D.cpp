#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
int n,m;
vector<int> e[maxn];
int col[maxn];
int num[7];

bool ck(int u){
	if (n-num[col[u]]!=e[u].size()) return 1;
	for (auto c:e[u]){
		if (col[c]==col[u]) return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	memset(num,0,sizeof(num));
	num[1]=n;
	for (int i=1;i<=n;++i){
		col[i]=1;
	}
	for (int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (auto c:e[1]){
		col[c]=2;
		num[1]--;
		num[2]++; 
	}
	if (e[1].size()==0){
		cout<<-1;
		return 0;
	}
	for (auto c:e[e[1][0]]){
		if (col[c]==2){
			col[c]=3;
			num[2]--;
			num[3]++;
		}
	}
	if (num[3]==0){
		cout<<-1;
		return 0;
	}
	for (int i=1;i<=n;++i){
		if (ck(i)){
			cout<<-1<<endl;
			return 0;
		}
	}
	for (int i=1;i<=n;++i){
		cout<<col[i]<<" ";
	}
	return 0;
}