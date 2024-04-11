#include <bits/stdc++.h>
#define P(a) {cout<<a<<'\n';exit(0);}
using namespace std;
int w=0,n,k;string a,c;
int v[100001][2];
void dfs(int i, bool b){
    if(i>n) P("YES");
    if(i<w) return;
    if(b) {if(c[i]=='X') return;}
    else  {if(a[i]=='X') return;}
    if(v[i][b]) return;
    v[i][b]=1;w++;
    dfs(i-1,b);
dfs(i+k,!b);
dfs(i+1,b);
w--;
}int main(){
cin>>n>>k>>a>>c;
dfs(0,0);
P("NO");
}