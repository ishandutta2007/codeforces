#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int n = 202;
int M;
bool dp[4][n][n];
bool sol[3][n][n];
pii solab[3][n][n];
pii nxt[4][n][n];
vector<pii> res[4][n][n];
bool dp2[n][n];
bool sol2[n][n];
pii solab2[n][n];
pii nxt2[n][n];
vector<pii> res2[n][n];
vector<pii> resGes[3][n][n];

void calcDP(){
	dp[0][0][0] = true;
	for(int m=1; m<=3; m++){
		int satzp = 25;
		for(int a=satzp; a<=200; a++){
			for(int b=0; b<a-1; b++){
				for(int x=0; x<=b; x++){
					int pa = a - max(satzp, x+2);
					if(dp[m-1][pa][b-x]){
						dp[m][a][b] = true;
						nxt[m][a][b] = {pa, b-x};
						for(auto p : res[m-1][pa][b-x]){
							res[m][a][b].push_back(p);
						}
						res[m][a][b].push_back({max(satzp, x+2), x});
						goto end;
					}
				}
end: ;
			}
		}
	}

	int satzp = 15;
	for(int a=satzp; a<=200; a++){
		for(int b=0; b<a-1; b++){
			for(int x=0; x<=b; x++){
				int pa = a - max(satzp, x+2);
				if(dp[2][pa][b-x]){
					dp2[a][b] = true;
					nxt2[a][b] = {pa, b-x};
					for(auto p : res[2][pa][b-x]){
						res2[a][b].push_back(p);
					}
					res2[a][b].push_back({max(satzp, x+2), x});
					goto end2;
				}
			}
end2: ;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	calcDP();
	for(int a=0; a<=200; a++){
		for(int b=0; b<=200; b++){
			for(int m=0; m<=2; m++){
				for(int pa=0; pa<=a; pa++){
					for(int pb=0; pb<=b; pb++){
						if(m<2 && dp[3][pa][pb] && dp[m][b-pb][a-pa]){
							sol[m][a][b] = true;
							for(auto p : res[m][b-pb][a-pa]){
								resGes[m][a][b].push_back(p);
							}
							for(auto p : res[3][pa][pb]){
								resGes[m][a][b].push_back({p.second, p.first});
							}
							goto end;
						}
						else if(m == 2 && dp2[pa][pb] && dp[m][b-pb][a-pa]){
							sol[m][a][b] = true;
							for(auto p : res[m][b-pb][a-pa]){
								resGes[m][a][b].push_back(p);
							}
							for(auto p : res2[pa][pb]){
								resGes[m][a][b].push_back({p.second, p.first});
							}
							goto end;
						}
					}
				}
end: ;
			}
		}
	}
	cin >> M;
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		bool found = false;
		for(int i=0; i<=2; i++){
			if(!found && sol[i][a][b]){
				cout << "3:" << i << "\n";
				for(auto p : resGes[i][a][b]){
					cout << p.second << ":" << p.first << " ";
				}
				cout << "\n";
				found = true;
			}
		}
		for(int i=2; i>=0; i--){
			if(!found && sol[i][b][a]){
				cout << i << ":3" << "\n";
				for(auto p : resGes[i][b][a]){
					cout << p.first << ":" << p.second << " ";
				}
				cout << "\n";
				found = true;
			}
		}
		if(!found)
			cout << "Impossible\n";
	}

	return 0;
}