#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);ios_base::sync_with_stdio(0);
  
  int width = 0, n; cin>>n;
  int a[n];
  for (int i = 0; i < n; i++) cin>>a[i];
  
  int above = 0, below = 0, tmp = 0, f = 1;
  for (int i = 0; i < n; i++){
    width += a[i];
    tmp += a[i]*f;
    f*=-1;
    if (tmp > above) above = tmp;
    if (tmp < below) below = tmp;
    // cout<<i<<' '<<tmp<<endl;
  }
  
  int height = above - below;
  // cout<<above<<' '<<below<<endl;
  // cout<<height<<' '<<width<<endl;
  
  int tmp_h = below + height-1, tmp_w = 0, way = 1;
  char graph[width][height], c = '/';
  memset(graph, ' ', sizeof(char)*width*height);
  
  for (int i = 0; i < n; i++){
    for (int j = 0; j < a[i]; j++){
      // cout<<tmp_w+j<<' '<<tmp_h - way*j<<' '<<c<<endl;
      graph[tmp_w+j][tmp_h - way*j] = c;
    }
    tmp_w += a[i];
    tmp_h += (a[i]-1)*-way;
    way = (way == 1? -1 : 1);
    c = (c == '/'? '\\' : '/');
  }
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
      cout<<graph[j][i];
    }
    cout<<endl;
  }
}