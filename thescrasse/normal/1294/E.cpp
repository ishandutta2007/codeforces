// codice non mio

#include<bits/stdc++.h>
using namespace std;

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

  int n, m, x, mosse, max, lol, i, res;
  res = 0;
  max=0;
  cin>>n>>m;
  int a[n][m];
  int apparizioni[n+1];
  int differenza[n+1];
  for(int c=0; c<n; c++) {
    for(int d=0; d<m; d++) {
      cin>>a[c][d];
    }
  }
  // cout << "ok" << endl;
  for(int c=0; c<m; c++) {
      // cout << c << endl;
    for(int sku=0;sku<n+1;sku++) {
      apparizioni[sku]=0;
      // cout<<"azzero"<<endl;
    }
    // cout<<"stop" << endl;
    for(int d=0;d<n;d++) {
      if(a[d][c]%m==(c+1)%m && a[d][c]<=m*n) {
        mosse=((d-(a[d][c] - 1)/(m))+m*n)%n;
        apparizioni[mosse]++;
        // cout << apparizioni[mosse] << endl;
        // cout<<mosse<<endl;
      } else {
          // cout << -1 << endl;
      }
    }
    for (i = 0; i < n + 1; i++) {
        // cout << apparizioni[i] << ' ';
    }
    // cout << endl;
    //cout<<"stop2";
    for(int sku=0; sku<n;sku++){
      differenza[sku]=apparizioni[sku]-sku;
    }
    for (i = 0; i < n + 1; i++) {
        // cout << differenza[i] << ' ';
    }
    // cout << endl;
    max = -100000010;
    for(int sku=0;sku<n;sku++) {
      if(differenza[sku]>max) {
        max=differenza[sku];
        lol=sku;
      }
    }
    //cout<<"stop 3";
    // cout << lol << endl;
    // cout << lol+(n-apparizioni[lol]) << endl;
     res=res+lol+(n-apparizioni[lol]);
  }

  cout<<res;
  return 0;
}