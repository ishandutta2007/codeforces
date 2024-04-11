#include <bits/stdc++.h>
using namespace std;

auto a = bitset<100000>();

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
int n, m;
cin >> n >> m;
string s;
cin >> s;
for (int i = 0; i + 2 < n; i++){
if (s[i]=='a' &&s[i+1]=='b'&&s[i+2]=='c') a[i]=1;
}
for (int i = 0; i < m; i++){
int q;
string c;
cin >> q >> c;
s[q-1]=c[0];
for(int j = -2;j<=2;j++){
if(q-1+j < 0 || q + j+1>=n) continue;
a[q-1+j] = (s[q-1+j]=='a'&&s[q+j]=='b'&&s[q+1+j]=='c');
}
cout << a.count() << '\n';
}
}