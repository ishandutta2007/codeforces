#include <bits/stdc++.h>
using namespace std;


int main() {
  int no_of_edge,no_of_vertex;
  int input1,input2;
  cin >> no_of_vertex >> no_of_edge;
  vector<vector<int> > adj(no_of_vertex+1);
  for(int i=0;i<no_of_edge;i++){
    cin >> input1 >> input2;
    adj[input1].push_back(input2);
    adj[input2].push_back(input1);
  }
  int maxedge = -1;
  int maximum = 0;
  for(int i=1;i<=no_of_vertex;i++){
    if(adj[i].size()>maximum){
      maxedge = i;
      maximum = adj[i].size();
    }

  }
  deque<int> q1;
  vector<bool> visited(no_of_vertex+1,0);
  q1.push_back(maxedge);
  visited[maxedge] = 1;
  while(q1.size()!=0){
    int a = q1.front();
    q1.pop_front();
    for(auto k:adj[a]){
      if(visited[k]==false){
        cout << a << " " << k << "\n";
        q1.push_back(k);
        visited[k] = true;
      }
    }
  }
  
}