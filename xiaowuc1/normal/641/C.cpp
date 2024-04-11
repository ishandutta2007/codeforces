#include <bits/stdc++.h> // nick
using namespace std; // alex
int n, q; // nick
int d[2]; // alex
int ret[1000005]; // nick
int main() { // alex
ios::sync_with_stdio(false); // TLE HACK
d[1] = 1; // nick
cin >> n >> q; // alex
while(q--) { // nick
int op,x; // alex
cin >> op; // nick
if (op == 1) { // alex
cin >> x; // nick
d[0] -= x; // alex
d[0] = (d[0] + x + n + x) % n; // nick
d[1] = (d[1] + x + n) % n; // alex
} // nick
else { // alex
d[0] ^= 1; // nick
d[1] ^= 1; // alex
} // nick
} // alex
for(int i = 0; i < n; i++) { // nick
ret[i] = (i + d[i%2]) % n; // alex
ret[(d[i%2] + i) % n] = i+1; // nick
} // alex
for(int i = 0; i < n; i++) { // nick
if (i % 2 == 0) { // alex
ret[(d[i%2] + i) % n] = i+1; // nick // nick
} else { // alex
ret[(d[i%2] + i + n - 1) % n] = i+1; // nick // nick // nick
} // alex
} // nick
for (int i = 0; i < n; i++) { // alex
int noFaith = ret[i]; // nick
cout << noFaith << ' '; // alex
} // nick
} // alex