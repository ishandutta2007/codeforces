/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c = pow(10,4);
     int n,m;
    cin>>n>>m;
    vector<int> adj[2*c+1];
    int x=n;
    for(int i=1;i<=2*c;i++)
    {
        if(i<=c)
        {
            adj[i].PB(2*i);
        }
        if(i>1)
        {
            adj[i].PB(i-1);
        }
    }
    queue<int> q;
bool visited[2*c+1];
int distance[2*c+1];
    visited[x] = true;
distance[x] = 0;
q.push(x);
while (!q.empty()) {
int s = q.front(); q.pop();
// process node s
for (auto u : adj[s]) {
if (visited[u]) continue;
visited[u] = true;
distance[u] = distance[s]+1;
q.push(u);
}
}
    cout<<distance[m];
    
     return 0;
}