#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
int n, m;
cin>>n>>m;
if (n > m) { swap(n, m); }
if (n == 1) { int bon = m - m % 6; vector<int> anses{0, 0, 0, 0, 2, 4}; cout<<bon + anses[m % 6]<<endl; return 0; }
if (n == 2) {
if (m >= 8) { cout<<2*m<<endl; return 0; }
vector<int> anses{0, 0, 0, 4, 8, 10, 12, 12};
cout<<anses[m]<<endl; 
return 0;
}
cout<<n*m - (n * m) % 2<<endl;
return 0;
}