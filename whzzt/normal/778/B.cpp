#include "bits/stdc++.h"
using namespace std;

const int N = 5005, M = 1005;
int n,m,id1[N],id2[N],opt[N],s0,s1,r0[M],r1[M];
string s[N],id,tmp;
map <string, int> data;
bool f[2][N][M];

int main(){
	#ifndef ONLINE_JUDGE
		freopen ("b.in","r",stdin);
		freopen ("b.out","w",stdout);
	#endif
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> id, data[id] = i, cin >> tmp, cin >> tmp;
		if (tmp[0] == '0' || tmp[0] == '1') s[i] = tmp;
		else {
			id1[i] = data[tmp];
			cin >> tmp;
			switch (tmp[0]){
				case 'A': opt[i] = 1; break;
				case 'O': opt[i] = 2; break;
				case 'X': opt[i] = 3; break;
			}
			cin >> tmp;
			id2[i] = data[tmp];
		}
	}
	for (int j=0; j<m; j++){
		s0 = s1 = 0;
		f[0][0][j] = 0, f[1][0][j] = 1;
		for (int i=1; i<=n; i++){
			switch (opt[i]){
				case 0 : f[0][i][j] = f[1][i][j] = s[i][j] - '0'; break;
				case 1 :
					f[0][i][j] = f[0][id1[i]][j] & f[0][id2[i]][j];
					f[1][i][j] = f[1][id1[i]][j] & f[1][id2[i]][j];
					break;
				case 2 :
					f[0][i][j] = f[0][id1[i]][j] | f[0][id2[i]][j];
					f[1][i][j] = f[1][id1[i]][j] | f[1][id2[i]][j];
					break;
				case 3 :
					f[0][i][j] = f[0][id1[i]][j] ^ f[0][id2[i]][j];
					f[1][i][j] = f[1][id1[i]][j] ^ f[1][id2[i]][j];
					break;
			}
			s0 += f[0][i][j], s1 += f[1][i][j];
		}
		r0[j] = s0 > s1 ? 1 : 0;
		r1[j] = s0 < s1 ? 1 : 0;
	}
	for (int i=0; i<m; i++) cout << r0[i]; cout << endl;
	for (int i=0; i<m; i++) cout << r1[i];
	return 0;
}