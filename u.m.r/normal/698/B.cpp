#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int a[MAXN];
vector<int> E[MAXN], Lp;
int vis[MAXN];

void dfs(int fa, int x){
	vis[x] = 2;
	for(int i = 0; i < E[x].size(); i++){
		int y = E[x][i];
		if (y != fa && vis[y] != 2)
			dfs(x, y);
	}
}

int work(int x){
	while(!vis[x]){
		vis[x] = 1;
		x = a[x];
	}
	dfs(0, x);
	return x;
}

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		E[i].clear(), vis[i] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		E[a[i]].push_back(i);
	//	E[i].push_back(i);
	}
	Lp.clear();
	int cnt = 0, flg = -1;
	for(int i = 1; i <= n; i++)
		if (!vis[i]){
			int x = work(i);
			Lp.push_back(x);
			if (a[x] == x && flg == -1)
				flg = x;
			cnt++;
		}
/*	cout<<cnt<<' '<<flg<<endl;
		for(int i = 0; i < Lp.size(); i++)
			cout<<Lp[i]<<' '; cout<<endl;
*/	if (flg == -1){
		printf("%d\n", cnt);
		for(int i = 0; i < Lp.size(); i++)
			a[Lp[i]] = Lp[0];
		for(int i = 1; i <= n; i++)
			printf("%d%c", a[i], " \n"[i == n]);
	}
	else{
		printf("%d\n", cnt - 1);
		for(int i = 0; i < Lp.size(); i++)
			a[Lp[i]] = flg;
		for(int i = 1; i <= n; i++)
			printf("%d%c", a[i], " \n"[i == n]);
	}
	return 0;
}