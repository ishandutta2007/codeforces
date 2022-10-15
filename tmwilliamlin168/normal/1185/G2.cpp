#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=50, mxA=2500, M=1e9+7, MG1=5508;
int n, T, id[mxN+1][mxN+1][mxN+1], ans;
vector<int> v[3];
int dp1[MG1][mxA+1];
int dp2[MG1][3];

void am(int &x, int y) {
	x=(x+y)%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> T;
	for(int i=0, t, g; i<n; ++i) {
		cin >> t >> g;
		v[g-1].push_back(t);
	}

	if(v[0].size()<v[1].size())
		swap(v[0], v[1]);
	if(v[1].size()<v[2].size())
		swap(v[1], v[2]);
	if(v[0].size()<v[1].size())
		swap(v[0], v[1]);
	for(int i=0, a=0; i<=v[0].size(); ++i)
		for(int j=0; j<=v[1].size(); ++j)
			for(int k=0; k<=v[2].size(); ++k)
				id[i][j][k]=a++;
	dp1[0][0]=1;
	for(int a=0; a<v[0].size(); ++a) {
			for(int t=T-v[0][a]; t>=0; --t)
		for(int i=0; i<=a; ++i) {
				am(dp1[id[i+1][0][0]][t+v[0][a]], dp1[id[i][0][0]][t]);
		}
	}
	for(int a=0; a<v[1].size(); ++a) {
				for(int t=T-v[1][a]; t>=0; --t)
		for(int i=0; i<=v[0].size(); ++i)
			for(int j=0; j<=a; ++j)
					am(dp1[id[i][j+1][0]][t+v[1][a]], dp1[id[i][j][0]][t]);
	}
	for(int a=0; a<v[2].size(); ++a) {
					for(int t=T-v[2][a]; t>=0; --t)
		for(int i=0; i<=v[0].size(); ++i)
			for(int j=0; j<=v[1].size(); ++j)
				for(int k=0; k<=a; ++k)
						am(dp1[id[i][j][k+1]][t+v[2][a]], dp1[id[i][j][k]][t]);
	}

	dp2[0][0]=1;
	ll fi=1;
	for(int i=0, a=0; i<=v[0].size(); ++i, fi=fi*i%M) {
		ll fj=1;
		for(int j=0; j<=v[1].size(); ++j, fj=fj*j%M) {
			ll fk=1;
			for(int k=0; k<=v[2].size(); ++k, fk=fk*k%M, ++a) {
				if(i) {
					am(dp2[a][0], dp2[id[i-1][j][k]][1]);
					am(dp2[a][0], dp2[id[i-1][j][k]][2]);
					if(!id[i-1][j][k])
						am(dp2[a][0], dp2[id[i-1][j][k]][0]);
				}
				if(j) {
					am(dp2[a][1], dp2[id[i][j-1][k]][0]);
					am(dp2[a][1], dp2[id[i][j-1][k]][2]);
				}
				if(k) {
					am(dp2[a][2], dp2[id[i][j][k-1]][0]);
					am(dp2[a][2], dp2[id[i][j][k-1]][1]);
				}
				for(int l=0; l<3; ++l) {
					ans=(ans+fi*fj%M*fk%M*dp2[a][l]%M*dp1[a][T])%M;
				}
			}
		}
	}

	cout << ans;
}