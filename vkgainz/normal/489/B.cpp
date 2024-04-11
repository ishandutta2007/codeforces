#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <cctype> 
#include <string> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <functional>
#include <string>
using namespace std;


int main() {

   //freopen("input.txt", "r", stdin); //scan in from external txt file

    int N;
    cin >> N;
    int n[N];
    for(int i = 0; i < N; i++) {
        cin >> n[i];
    }
    int Q;
    cin >> Q;
    int m[Q];
    for(int i = 0; i < Q; i++) {
        cin >> m[i];
    }
    sort(n, n + N);
    sort(m, m + Q);
    
    /*
    int aN;
    int d[aN];
    int nd[]
    if N <= Q{
      aN = N
      d = n
    }
    if Q <= N{
      aN = Q
      d = m
    }
    */
   
    
    int ans = 0;
    int st = 0;
    for(int i = 0; i < N; i++) {
      int match = -1;
      for(int k = st; k < Q; k++) {
          if((n[i] - m[k]) <= 1 && (n[i] - m[k]) >= -1) {
              match = k;
              ans++;
              break;
          }
      }
      if(match >= 0) {
        st = match + 1;
      }
    }
   
    cout << ans;
  }