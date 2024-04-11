#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

struct Coord{int x,y;};
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    vector<Coord> arr; arr.push_back({0,0});
    for (int i=1;i<=2*n+1;i+=2){
        arr.push_back({i-1,i});
        arr.push_back({i-1,i+1});
        arr.push_back({i,i-1});
        arr.push_back({i,i+1});
        arr.push_back({i+1,i-1});
        arr.push_back({i+1,i});
        arr.push_back({i+1,i+1});
    }
    cout << arr.size() << '\n';
    for (Coord a:arr){
        cout << a.x << " " << a.y << '\n';
    }

}