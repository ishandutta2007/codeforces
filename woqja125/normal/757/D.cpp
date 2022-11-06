#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
char in[100];
vector<pair<int, int>> l[100];
const int MOD = 1000000007;
int d[100][1<<20];
int m[100];
int main()
{
	int n;
	scanf("%d%s", &n, in+1);
	for(int i=1; i<=n; i++){
		int x=0;
		for(int j=i; j<=n; j++){
			x = x*2 + in[j]-'0';
			if(x>20) break;
			if(x!=0)l[i].push_back({j, x-1});
		}
	}
	int ans = 0;
	for(int i=0; i<=n; i++)
		d[i][0] = 1;
	for(int s=0; s<n; s++){
		for(int b=0; b<=m[s]; b++)if(d[s][b])for(auto &e: l[s+1]){
			int &x = d[e.first][b | (1<<e.second)];
			x = (x+d[s][b])%MOD;
			if(m[e.first] < (b | (1<<e.second))) m[e.first] = (b | (1<<e.second));
		}
	}
	for(int i=1; i<=n; i++){
		for(int b=2; b<=m[i]+1; b*=2){
			ans = (ans + d[i][b-1])%MOD;
		}
	}
	printf("%d", ans);
	return 0;
}