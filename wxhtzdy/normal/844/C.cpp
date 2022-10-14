#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
int n,a[N];
vector<int> E[N],ans;
bool was[N];
void DFS(int u){
    was[u]=true;
    for(int c:E[u])if(!was[c]){
        ans.pb(c);
        DFS(c);
    }
}
int main(){
    scanf("%i",&n);
    int b[n+1];
    for(int i=1;i<=n;i++)scanf("%i",&a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    map<int,int> hsh;
    for(int i=1;i<=n;i++)hsh[b[i]]=i;
    for(int i=1;i<=n;i++)a[i]=hsh[a[i]];
    for(int i=1;i<=n;i++)E[a[i]].pb(i);
    vector<vector<int>> v;
    for(int i=1;i<=n;i++)if(!was[i]){
        ans.clear();
        ans.pb(i);
        DFS(i);
        v.pb(ans);
    }
    printf("%i\n",(int)v.size());
    for(int i=0;i<(int)v.size();i++){
        printf("%i ",(int)v[i].size());
        for(int c:v[i])printf("%i ",c);
        printf("\n");
    }
    return 0;
}