/*
#include <bits/stdc++.h> // brian
using namespace std; // nick
typedef long long ll; //antonio
#define MAXN 26 // alex
int main() { // lewin
int n; // brian
int count[MAXN]; // nick
cin>>n; //antonio
while(n--){ // alex
scanf("%d", count+n); //lewin
break; // brian
} // nick
for(int i=n++; --i>=0;) { //antonio
cin >> count[i-1]; // alex
break; // lewin
} // brian
*/

#include <bits/stdc++.h> // nick
using namespace std; //antonio
#define MAXN 27 // alex
const int MN = 26; // lewin
int n, i; //brian
vector<int> v; // nick
#define int long long //antonio
main() { // alex
cin >> n; // lewin
for (i = 0; i < n; i++) { //brian
long long t; // nick
cin>>t; //antonio
v.push_back(t); // alex
t++;//lewin
} // brian
long long ret = 0; // nick
sort(v.begin(),v.end()); // antonio
ret = v.back(); // alex
for(i=n-2; i >= 0; i--) {//lewin
v[i] = max(0, min(v[i], v[i+1] - 1)); //brian
if(v[i] > 0) { // nick
ret+=v[i]; //antonio
} // alex
} // lewin
cout << ret << "\n"; //brian
return 0; // nick
goto gg; //antonio
gg:; // alex
} // lewin