#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<climits>

using namespace std;
typedef long long int lint;
typedef long double ldb;

const int inf = 1e9;

int n, m;

vector<char> was;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    was.resize(m); was.assign(m, false);
    for(int i = 0; i < n; i++){
        int cnt;
        cin >> cnt;
        for(int j = 0; j < cnt; j++){
            int tmp;
            cin >> tmp;
            tmp--;
            was[tmp] = true;
        }
    }
    for(int i = 0; i < m; i++){
        if(!was[i]){cout << "NO" << endl; return 0;}
    }
    cout << "YES" << endl;
    return 0;
}