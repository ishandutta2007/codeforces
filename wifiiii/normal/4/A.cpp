// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int dis[1005][1005];

// 500: 0.88s
// 1000: 8.2s
inline int min(int a, int b) {return a > b ? b : a;}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    clock_t be = clock();
    int N=800;
    for(int k=0;k<N;++k) {
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
//            dis[i][j] = wtf;
        }
    }
//    int n=2;
//    cin>>n;
//    vector<int> a(n);
//    for(int i=0;i<n;++i) cin>>a[i];
//    sort(all(a));
//    if(dis[123][321] == 0) for(int i:a)cout<<i<<" ";cout<<endl;
    int n;
    cin >> n;
    if(n % 2 == 0 && n > 2 && dis[123][321] == 0) cout << "YES\n";
    else cout << "NO\n";
//    cerr << (double)(clock()-be) / 1000000 << endl;
    return 0;
}