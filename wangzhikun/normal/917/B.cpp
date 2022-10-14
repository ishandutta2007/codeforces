// Author : WangZhikun
// Date   : 2018.07.25

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

struct edge{
	int u,v;
	char w;
};

vector<edge> egs[110];
int n,m,ans[1000010];
int gmax(int a,int b){return a>b?a:b;}

bool dfs(int fs,int sc,int li){
	int chs = ((fs*101+sc)*27+li);
	if(ans[chs] !=-1)return ans[chs];
	for(int i=0;i<egs[fs].size();i++){
		if(egs[fs][i].w>=li && dfs(sc,egs[fs][i].v,egs[fs][i].w) == 0){
			ans[chs] = 1;
			return 1;
		}
	}
	ans[chs] = 0;
	return 0;
}
int main() {
	for(int i=0;i<1000000;i++)ans[i] = -1;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		edge ceg;
		cin>>ceg.u>>ceg.v>>ceg.w;
		ceg.w-='a';
		egs[ceg.u].push_back(ceg);
	}
	for(int mx = 1;mx<=n;mx++){
		for(int lc = 1;lc<=n;lc++){
			if(dfs(mx,lc,0))cout<<'A';
			else cout<<'B';
		}
		cout<<endl;
	}
	return 0;
}