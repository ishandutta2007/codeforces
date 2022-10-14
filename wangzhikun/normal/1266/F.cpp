#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) //cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,u,v;
vector<int> G[500050];
int max(int a,int b){
	return a>b?a:b;
}
int depth[500050],ud[500050];
int mxans[500050];
void dfs(int num,int fa = 0){
	depth[num] = 1;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		dfs(ct,num);
		depth[num] = max(depth[num],depth[ct]+1);
	}
}

vector<int> avd[500050];
vector<pii> szab[500050];

void dfs2(int num,int fa = 0){
	priority_queue<int> Se;
	Se.push(1);
	if(fa){
		Se.push(ud[num]+1);
		avd[num].push_back(ud[num]);
	}
	for(auto ct:G[num]){
		if(ct == fa)continue;
		Se.push(depth[ct]+1);
		avd[num].push_back(depth[ct]);
	}
	sort(avd[num].begin(),avd[num].end());
	for(auto ct:G[num]){
		if(ct == fa)continue;
		if(depth[ct]+1 == Se.top()){
			Se.pop();
			ud[ct] = Se.top();
			Se.push(depth[ct]+1);
		}else{
			ud[ct] = Se.top();
		}
		dfs2(ct,num);
	}
	sort(szab[num].begin(),szab[num].end());
	mxans[1] = max(mxans[1],G[num].size()+1);
	int cmx = 0,cp = szab[num].size()-1;
	for(int i=(int)avd[num].size()-1;i>=0;i--){
		while(cp>=0 && szab[num][cp].first>=avd[num][i]){
			cmx = max(cmx,szab[num][cp].second);
			if(cmx>0 && i!=avd[num].size()-1)
				mxans[szab[num][cp].first*2] = max(mxans[szab[num][cp].first*2],cmx+avd[num].size()-i-3);
			cp--;
		}
		if(cmx>0)
			mxans[avd[num][i]*2] = max(mxans[avd[num][i]*2],cmx+avd[num].size()-i-2);
	}
	while(cp>=0){
		cmx = max(cmx,szab[num][cp].second);
		if(cmx>0 && avd[num].size())
			mxans[szab[num][cp].first*2] = max(mxans[szab[num][cp].first*2],cmx+avd[num].size()-2);
		cp--;
	}
	for(int i=0;i<avd[num].size();i++){
		mxans[avd[num][i]*2] = max(mxans[avd[num][i]*2],avd[num].size()-i);
		mxans[avd[num][i]*2-1] = max(mxans[avd[num][i]*2-1],avd[num].size()-i);
		if(i!=avd[num].size()-1 && avd[num][i]!=avd[num][i+1])
			mxans[avd[num][i]*2+1] = max(mxans[avd[num][i]*2+1],avd[num].size()-i);
		szab[fa].push_back(make_pair(avd[num][i],avd[num].size()-i));
	}
}

int main() {
	read(n);
	for(int i=1;i<n;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	dfs2(1);
	mxans[n] = max(mxans[n],1);
	mxans[n-1] = max(mxans[n-1],1);
	for(int i=n;i>=1;i--){
		mxans[i] = max(mxans[i],mxans[i+2]);
	}
	for(int i=1;i<=n;i++){
		cout<<mxans[i];
		if(i!=n)cout<<' ';
	}
	cout<<endl;
	return 0;
}