// Author : WangZhikun
// Date   : 2018.07.26

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
#define N 1200030
int ans[N][2];
int n,fa[N],val[N],u,v,lson[N],rson[N];
char ty[N];
bool calc(int num){
	if(ty[num] == 'N')return !val[lson[num]];
	if(ty[num] == 'A')return val[lson[num]]&val[rson[num]];
	if(ty[num] == 'O')return val[lson[num]]|val[rson[num]];
	if(ty[num] == 'X')return val[lson[num]]^val[rson[num]];
	return 0;
}
bool ddd(int num,int cur){
	//cout<<num<<' '<<cur<<endl;
	if(ans[num][cur]!=-1)return ans[num][cur];
	val[num] = !val[num];
	int cv = calc(fa[num]);
	val[num] = !val[num];
	int ret = ddd(fa[num],cv);
	ans[num][cur] = ret;
	return ret;
}
bool dfs(int num){
	if(ty[num] == 'I')return val[num];
	if(ty[num] == 'N')return val[num] = !dfs(lson[num]);
	if(ty[num] == 'A')return val[num] = dfs(lson[num])&dfs(rson[num]);
	if(ty[num] == 'O')return val[num] = dfs(lson[num])|dfs(rson[num]);
	if(ty[num] == 'X'){
		//cout<<num<<' '<<dfs(lson[num])<<' '<<dfs(rson[num])<<endl;
		//cout<<(dfs(lson[num])^dfs(rson[num]))<<endl;
		return val[num] = dfs(lson[num])^dfs(rson[num]);
	}
	return 0;
}
char op[10];
int main() {
	cin>>n;
	for(int i=2;i<=n+2;i++)ans[i][0] = ans[i][1] = -1;
	ans[1][0] = 0;ans[1][1] = 1;
	for(int i=1;i<=n;i++){
		cin>>op;
		ty[i] = op[0];
		if(op[0] == 'I'){
			cin>>u;
			val[i] = u;
		}else if(op[0] == 'N'){
			cin>>u;
			fa[u] = i;
			lson[i] = u;
		}else{
			cin>>u>>v;
			lson[i] = u;rson[i] = v;
			fa[u] = fa[v] = i;
		}
	}
	dfs(1);
	//cout<<ty[31]<<endl;
	//cout<<lson[31]<<' '<<rson[31]<<endl;
	//cout<<(val[37]^val[39])<<endl;
	for(int i=2;i<=n;i++)if(val[i] == 0 || val[i] == 1)ans[i][val[i]] = val[1];
	//for(int i=1;i<=n;i++)cout<<i<<' '<<val[i]<<endl;;
	//cout<<endl;
	for(int i=1;i<=n;i++)if(ty[i] == 'I')cout<<ddd(i,!val[i]);
	cout<<endl;
	return 0;
}