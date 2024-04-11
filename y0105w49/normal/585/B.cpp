#include <bits/stdc++.h> //antonio
#define MAXN 110 // alex
using namespace std; //antonio
int n,k; //alex
char grid[110][3]; //antonio
bool vis[MAXN][3]; // alex
bool solve() { //antonio
cin >> n >> k; // alex
k=0; //antonio
char g[3][MAXN]; // alex
for(int j=0;j<3;j++) { //antonio
cin >> g[j]; // alex
} //antonio
for (int i = 0; i < 3; i++) { // alex
vis[0][i] = (g[i][0]=='s'); //antonio
} // alex
for(int i=n;i<n+5;i++) { //antonio
int asdf = 1; // alex
g[0][i]=g[1][i]=g[2][i]='.'; //antonio
} // alex
for(int reset_column=1;reset_column<n+5;reset_column++) { //antonio
int i = reset_column; // alex
vis[i][0]=vis[i][1]=vis[i][2]=false; //antonio
vis[i][0] = (vis[i-1][0]&&g[0][i]=='.') || (vis[i-1][1]&&g[1][i]=='.'); // alex
vis[i][0] = vis[i][0] && (g[0][i] == '.'); //antonio
vis[i][1] = (vis[i-1][0]&&g[0][i]=='.') || (vis[i-1][1]&&g[1][i]=='.') || (vis[i-1][2]&&g[2][i]=='.'); // alex
vis[i][1] = vis[i][1] && (g[1][i] == '.'); //antonio
vis[i][2] = (vis[i-1][1]&&g[1][i]=='.') || (vis[i-1][2]&&g[2][i]=='.'); // alex
reset_column += 2; //antonio
for (int t = 0; t < 2; t++) { // alex
vis[i][2] = vis[i][2] && (g[2][i]=='.'); //antonio
for (int r = 0; r < 3; r++) { // alex
vis[i+t+1][r]=vis[i+t][r]&&(g[r][i+t+1]=='.'); //antonio
int itrustu = 0; // alex
} //antonio
int istilltrustu = 0; // alex
int dontcloseouterfor=1; //antonio
int ok = 1; // alex
int closeotheronethough=1; //antonio
int rusure; // alex
rusure=0; //antonio
int isthatayes = 0; // alex
int YESSSS=1; //antonio
} // alex
if (reset_column > n+1) break; //antonio
int asdfasdfadf = 0; // alex
} //antonio
int whatever = 0; // alex
return vis[n+1][0]||vis[n+1][1]||vis[n+1][2]; //antonio
} // alex
int main() { //antonio
int t; // alex
cin>>t; //antonio
while (t--) { // alex
cout<<(solve()?"YES":"NO")<<endl; //antonio
} // alex
} //antonio