#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], x[N];
vector <pair<int,int> > vec;
void read(){
    cin>>n;
    for (int i = 1; i <= n; ++i)cin>>a[i];
    for (int i = 1; i < n; ++i)if (a[i] > a[i + 1]) vec.push_back({a[i] - a[i + 1], i + 1});
}

int main() {
    int t;
    cin>>t;
    while (t--){
        vec.clear();
        read();
        sort(begin(vec), end(vec));
        reverse(vec.begin(),vec.end());
        int kk = n;
        for (auto p : vec) x[kk--] = p.second;
        while (kk) x[kk--] = 1;
        for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
        puts("");
    }
	return 0;
}