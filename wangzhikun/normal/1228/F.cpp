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
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,u,v,sz[500050],gm = 1e9;
vector<int> G[500050];
vector<int> gg;
void fdfs(int num,int fa = -1){
	sz[num] = 1;
	int cmx = 0;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		fdfs(ct,num);
		sz[num]+=sz[ct];
		cmx = max(cmx,sz[ct]);
	}
	cmx = max(cmx,(1<<n)-2-sz[num]);
	//cout<<"HOHO"<<num<<' '<<cmx<<endl;
	if(cmx<gm){
		gm = cmx;
		gg.clear();
		gg.push_back(num);
	}else{
		if(cmx==gm){
			gg.push_back(num);
		}
	}
}
void dfs(int num,int fa = -1){
	sz[num] = 1;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		dfs(ct,num);
		sz[num]+=sz[ct];
	}
}
bool csmp(int num,int v,int fa = -1){
	//cout<<"csmp "<<num<<' '<<v<<' '<<fa<<endl;
	if(v == 1 && G[num].size() == 1 && G[num][0] == fa)return 1;
	int cnt = 0,ok = 1;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		cnt++;
		ok&=csmp(ct,v-1,num);
	}
	return (ok == 1 && cnt == 2);
}

int ans = -1;
bool check(int num,int v,int fa = -1){
	int add = 0;
	if(fa == -1)add = 1;
	
	if(G[num].size()+add == 4){
		int cn1 = 0,cn2 = 0;
		for(auto ct:G[num]){
			if(ct == fa || ct == -1)continue;
			if(sz[ct] == (1<<(v-1))-1){
				if(csmp(ct,v-1,num))cn1++;
				else return 0;
			}else{
				if(sz[ct] == (1<<(v-2))-1){
					if(csmp(ct,v-2,num))cn2++;
					else return 0;
				}else{
					return 0;
				}
			}
		}
		if(cn1 == 1 && cn2 == 2){
			ans = num;
			return 1;
		}
	}
	
	if(G[num].size()+add == 2){
		int cnt = 0;
		for(auto ct:G[num]){
			if(ct == fa)continue;
			if(sz[ct] == 1){
				cnt++;
			}else{
				return 0;
			}
		}
		if(cnt == 1 && v == 2){
			ans = num;
			return 1;
		}
		return 0;
	}
	int cn1 = 0,cn2 = 0;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		if(sz[ct] == (1<<(v-1))-1){
			if(csmp(ct,v-1,num))cn1++;
			else return 0;
		}else{
			if(sz[ct] == (1<<(v-1))-2){
				if(check(ct,v-1,num))cn2++;
				else return 0;
			}else{
				return 0;
			}
		}
	}
	if(cn1 == 1 && cn2 == 1){
		return 1;
	}
	return 0;
}

int main() {
	read(n);
	for(int i=0;i<(1<<n)-3;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	fdfs(1);
	vector<int> tans;
	for(auto gi:gg){
		//debug(gi);
		dfs(gi);
		if(check(gi,n)){
			tans.push_back(ans);
		}
	}
	cout<<tans.size()<<endl;
	sort(tans.begin(),tans.end());
	for(auto ct:tans)cout<<ct<<' ';
	cout<<endl;
	return 0;
}