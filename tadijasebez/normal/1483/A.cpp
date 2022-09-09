#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%i",&t);
while(t--){
int n,m;
scanf("%i %i",&n,&m);
map<int,int> cnt;
vector<vector<int>> vs(m+1);
for(int i=1;i<=m;i++){
int sz;
scanf("%i",&sz);
while(sz--){
int x;
scanf("%i",&x);
vs[i].push_back(x);
}
if(vs[i].size()==1)cnt[vs[i][0]]++;
}
for(int i=1;i<=m;i++){
if(vs[i].size()!=1){
int best=vs[i][0];
for(int x:vs[i]){
if(cnt[best]>cnt[x])best=x;
}
vs[i][0]=best;
cnt[best]++;
}
}
bool ok=true;
for(auto it:cnt){
if(it.second>(m+1)/2)ok=false;
}
if(ok){
printf("YES\n");
for(int i=1;i<=m;i++)
printf("%i ",vs[i][0]);
printf("\n");
}else printf("NO\n");
}
return 0;
}