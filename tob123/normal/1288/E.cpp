#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sz(x) ((int) (x).size())

typedef pair<int,int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> T;
typedef long long ll;

//cout<< X.order_of_key(7)<<endl;
//cout<< *X.find_by_order(6)<<endl

const int n = 3e5+10;

T t;

int N, M;
int L[n], H[n];
int C[n];

int cnt = 0;

void pr(){
  for(int i=0; i<sz(t); i++){
    cout << t.find_by_order(i)->second << " ";
  }
  cout << endl;
  for(int i=1; i<=N; i++){
    cout << t.order_of_key(make_pair(C[i], i)) << " ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  for(int i=1; i<=N; i++){
    t.insert(make_pair(i,  i));
    L[i] = i;
    H[i] = i;
    C[i] = i;
  }
  for(int i=0; i<M; i++){
    int x;
    cin >> x;
    pii p = make_pair(C[x], x);
    H[x] = max(H[x], 1 + (int) (t.order_of_key(p)));
    t.erase(p);
    C[x] = cnt--;
    t.insert(make_pair(C[x], x));
    L[x] = 1;
    //pr();
  }
  for(int i=1; i<=N; i++){
    H[i] = max(H[i], 1+ (int) (t.order_of_key(make_pair(C[i], i))));
  }
  for(int i=1; i<=N; i++){
    cout << L[i] << " " << H[i] << "\n";
  }

  return 0;
}