/*input
3 3
3 1 2
5 3 4


8 7
1 1 3 1 5 3 7 1
5 7 4 8 1 3 5 2
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
const int N = 1e5+5;

int n,m;
vector<int> a,b;
vector<int> rep[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    a = vector<int>(n,0);
    b = vector<int>(n,0);
    
    for(auto &it:a) cin >> it;
    for(auto &it:b) cin >> it;
      
    loop(i,0,n-1){
      rep[a[i]].push_back(b[i]);
    }
    
    vector<int> vec;
    int nobody = 0;
    loop(i,1,m){
      if (rep[i].size()==0){
        nobody++;
        continue;
      }
      sort(rep[i].begin(),rep[i].end());
      loop(j,0,rep[i].size()-2){
        vec.push_back(rep[i][j]);
      }
    }
    sort(vec.begin(),vec.end());
    int sum = 0;
    loop(i,0,nobody-1) sum+=vec[i];
      cout << sum << endl;
}