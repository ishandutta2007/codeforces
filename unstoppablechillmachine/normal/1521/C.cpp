#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    vector<int> actual_perm(10);
    iota(all(actual_perm), 1);
    random_shuffle(all(actual_perm));
    int actual_pos_of_one = -1;
    for (int i = 0; i < SZ(actual_perm); i++) {
      if (actual_perm[i] == 1) {
        actual_pos_of_one = i + 1;
      }
    }
    int n = SZ(actual_perm);
    cin >> n;
    auto ask = [&actual_perm](int type, int pos1, int pos2, int x) {
      cout << "? " << type << ' ' << pos1 << ' ' << pos2 << ' ' << x << endl;
      int result;
      cin >> result;
      return result;
      /*if (type == 1) {
        return max(min(x, actual_perm[pos1 - 1]), min(x + 1, actual_perm[pos2 - 1]));
      } 
      return min(max(x, actual_perm[pos1 - 1]), max(x + 1, actual_perm[pos2 - 1]));*/
    };
    auto guess = [&actual_perm](vector<int>& permutation) {
      cout << "! ";
      for (auto elem : permutation) {
        cout << elem << ' ';
      }
      cout << endl;
      /*for (auto elem : actual_perm) {
        cout << elem << ' ';
      }
      cout << endl;
      assert(permutation == actual_perm);*/
    };
    int pos_of_one = -1;
    vector<int> cands;
    for (int i = 1; i + 1 <= n; i += 2) {
      int current = ask(2, i, i + 1, 1);
      if (current == 1) {
        pos_of_one = i;
        break;
      }
      else if (current == 2) {
        cands.push_back(i + 1);
      }
    }
    if (pos_of_one == -1) {
      if (n & 1) {
        cands.push_back(n);
      }
      if (SZ(cands) == 1) {
        pos_of_one = cands[0];
      }
      for (int i = 0; i < SZ(cands); i++) {
        for (int j = 0; j < SZ(cands); j++) {
          if (i == j) {
            continue;
          }
          if (ask(2, cands[i], cands[j], 1) == 1) {
            pos_of_one = cands[i];
          }
        }
      }  
    }
    assert(pos_of_one != -1);
    vector<int> answer(n);
    answer[pos_of_one - 1] = 1;
    for (int i = 1; i <= n; i++) {
      if (pos_of_one == i) {
        continue;
      }
      answer[i - 1] = ask(1, pos_of_one, i, n - 1);
    }
    guess(answer);
  }
}