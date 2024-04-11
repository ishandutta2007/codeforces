#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;
typedef long long int lint;

vector<int> cnt;
vector<int> maxt;
vector<int> tarr;
long long int total = 0ll;
int n, s;

int main(){
	ios_base::sync_with_stdio(false);
    cin >> n >> s;
    cnt.resize(s + 1);
    maxt.resize(s + 1);
    maxt.assign(s + 1, 0);
    tarr.resize(s + 1);
    for(int i = 0; i < n; i++){
        int f, t;
        cin >> f >> t;
        maxt[f] = max(maxt[f], t);
    }
    for(int i = s; i >= 0; i--){
        tarr[i] = max(maxt[i], ((i == s) ? 0 : tarr[i + 1] + 1));
    }
    cout << tarr[0] << endl;
	return 0;
}