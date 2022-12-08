#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#define For(i,j,k) for(int i = j;i <= (int)k;i ++)
#define Set(i,j) memset(i, j, sizeof(i))

using namespace std;
const int N = 130;
int Ans, G[N][N], all[N][N], some[N][N], none[N][N];
int mx;
void DFS(int n, int an, int sn, int nn){
	if(!sn && !nn) {
		Ans++;
		mx=max(mx,an);
	}
	//if(Ans > 1000) return;
	int key = some[n][1];
	For(j,1,sn){
		int v = some[n][j], tsn = 0, tnn = 0;
		if(G[key][v])continue;
		For(i,1,an) all[n+1][i] = all[n][i]; all[n+1][an+1] = v;
		For(i,1,sn) if(G[v][some[n][i]]) some[n+1][++tsn] = some[n][i];
		For(i,1,nn) if(G[v][none[n][i]]) none[n+1][++tnn] = none[n][i];
		DFS(n + 1, an + 1, tsn, tnn);
		some[n][j] = 0, none[n][++nn] = v;
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	Set(G, 0), Ans = 0;
	For(i,1,n)For(j,1,n)scanf("%d",&G[i][j]);
	For(i,1,n) some[1][i] = i;
	DFS(1, 0, n, 0);
	printf("%.10lf\n", 0.5*m*m/mx*(mx-1));
	return 0;
}