#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 310;

int N;
ll dp[MAXN][MAXN][6] = {0};
int x[MAXN], y[MAXN];
vector <pair <double, pair <int, int> > > p;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (j != i)
                p.push_back(make_pair (atan2 (y[j] - y[i], x[j] - x[i]), make_pair (i, j)));
    sort (p.begin(), p.end());
    for (int i = 0; i < N; i++)
		dp[i][i][0] = 1;
    for (int i = 0; i < p.size(); i++){
        int a = p[i].second.first, b = p[i].second.second;
        for (int c = 0; c < N; c++)
            for (int f = 0; f < 5; f++)
            	dp[c][b][f+1] += dp[c][a][f];
    }
    ll tot = 0;
    for (int i = 0; i < N; i++) tot += dp[i][i][5];
    cout << tot << "\n";
}