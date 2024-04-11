#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#define MP make_pair
#define PB push_back

typedef long long ll;

using namespace std;

const int N = 5005;
const int INF = 1000 * 1000 * 1000;

ll a[N];
ll old_a[N];
ll que[N][5];
ll ogr[N];

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	int n, m;
  cin>>n>>m;
  for (int i = 1; i <= n; i++) {
    //cin>>a[i];
    //old_a[i] = a[i];
    ogr[i] = INF;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= 4; j++) {
      cin>>que[i][j];
    }
    if (que[i][1] == 1) {
      for (int j = que[i][2]; j <= que[i][3]; j++) {
        a[j] += que[i][4];
      }
    } else {
      for (int j = que[i][2]; j <= que[i][3]; j++) {
        ogr[j] = min(ogr[j], que[i][4] - a[j]);
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    a[i] = ogr[i];
    //cout<<a[i]<<" ";
  }
  //cout<<endl; */
  for (int i = 1; i <= m; i++) {
    if (que[i][1] == 1) {
      for (int j = que[i][2]; j <= que[i][3]; j++) {
        a[j] += que[i][4];
      }
    } else {
      bool ok = false;
      for (int j = que[i][2]; j <= que[i][3]; j++) {
        ok |= (a[j] == que[i][4]);
      }
      if (!ok) {
        cout<<"NO"<<endl;
        return 0;
      }
    }
  }
  cout<<"YES"<<endl;
  for (int i = 1; i <= n; i++) {
    cout<<ogr[i]<<" ";
  }
  cout<<endl;
    
	
	// nie zapomnij o ll
	return 0;
}