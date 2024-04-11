#include <bits/stdc++.h>
using namespace std;

int main() {
int R,C;
cin >> R >> C;
for(int i =0; i < C; i++) cout << "#"; cout << "\n";
for(int i =0; i < R-1; i +=2) {
for(int j =0; j < C; j++) {
if(i%4 == 0) cout << ((j < C-1)?".":"#");
else cout << ((j > 0)?".":"#");}
cout << "\n";
for(int j =0; j < C; j++) cout << "#";
cout << "\n";}
}