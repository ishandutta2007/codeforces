#include <bits/stdc++.h>

using namespace std;

const int N=4e5+10;
int h[N];
vector <int> v[N];

void BFS(int st){
        queue <int> q;
        q.push(st);
        h[st]=1;
        while (!q.empty()){
                int x=q.front();q.pop();
                for(auto y:v[x]) if (!h[y]){
                        h[y]=1;
                        q.push(y);
                }

        }
}
int main(){
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=k;i++){
                int x,y;
                cin>>x>>y;
                v[x].push_back(y+n);
                v[y+n].push_back(x);
        }
        int ans=0;
        for(int i=1;i<=n+m;i++) if (!h[i]){
                ans++;
                BFS(i);
        }
        cout<<ans-1;
}