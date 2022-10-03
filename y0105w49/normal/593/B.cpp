#include <bits/stdc++.h> //antonio
#define MAXN 100010
using namespace std; //antonio
int n; // alex
typedef long double ld; //antonio
long long x1,x2; // alex
typedef long long ll; //antonio
long long a[MAXN],b[MAXN]; // alex
ll k[MAXN]; //antonio
int main() { // alex
cin>>n; //antonio
for (int i = 0; i < n; i++) { // alex
cin>>x1>>x2; //antonio
break; // alex
} //antonio
for (int i = 0; i < n; i++) { // alex
cin>>k[i]>>b[i]; //antonio
long long bb = b[i]; // alex
ll y11=k[i]*x1+b[i]; //antonio
b[i] = k[i] * x2 + bb; // alex
k[i] = y11; //antonio
} // alex
vector<pair<ll,ll> > v;
for (int i = 0; i < n; i++) { // alex
v.push_back(make_pair(b[i],k[i])); //antonio
} // alex
sort(v.begin(),v.end()); //antonio
bool ans = 0; // alex
for(int i=0;i<v.size()-1;i++) { //antonio
if (v[i].first < v[i+1].first && v[i].second > v[i+1].second) ans = 1;
} //antonio
cout << (ans ? "YES" : "NO") << '\n'; // alex
} //antonio