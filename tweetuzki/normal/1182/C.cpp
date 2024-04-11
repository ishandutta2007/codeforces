#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100000 + 5;

int N;
map<char, bool> IsVowel;
bool Mp[MaxN];
string A[MaxN];
vector<int> Vowel[MaxN], LastVow[MaxN][26];
vector<string> Ans[4];

void init() {
  IsVowel['a'] = IsVowel['e'] = IsVowel['i'] = IsVowel['o'] = IsVowel['u'] = true;
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> A[i];
}

inline int countVowel(const string &str) {
  int cnt = 0;
  for (int i = 0; str[i]; ++i)
    if (IsVowel[str[i]] == true) cnt++;
  return cnt;
}

inline int getLastVowel(const string &str) {
  int last = 0;
  for (int i = 0; str[i]; ++i)
    if (IsVowel[str[i]] == true) last = str[i] - 'a';
  return last;
}

inline bool check(int mid) {
  Ans[0].clear(); Ans[1].clear();
  Ans[2].clear(); Ans[3].clear();
  memset(Mp, false, sizeof Mp);

  int sum = 0;
  for (int c = 0; c < 26; ++c) {
    if (sum == mid) break;
    if (IsVowel[c + 'a'] == false) continue;
    for (int num = 1; num <= N; ++num) {
      if (sum == mid) break;
      for (int i = 0; i + 1 < (int) LastVow[num][c].size(); i += 2) {
        int u = LastVow[num][c][i], v = LastVow[num][c][i + 1];
        Ans[1].push_back(A[u]), Ans[3].push_back(A[v]);
        Mp[u] = Mp[v] = true;
        sum++;
        if (sum == mid) break;
      }
    }
  }
  if (sum != mid) return false;

  sum = 0;
  static int iter[MaxN];
  memset(iter, 0, sizeof iter);
  for (int c = 1; c <= N; ++c) {
    if (Vowel[c].empty()) continue;
    int u = -1, v = -1;
    for (int &i = iter[c]; i < (int) Vowel[c].size(); ++i) {
      int x = Vowel[c][i];
      if (Mp[x] == false) {
        u = x;
        break;
      }
    }
    if (u == -1) continue;
    for (int &i = iter[c]; i < (int) Vowel[c].size(); ++i) {
      int x = Vowel[c][i];
      if (x != u && Mp[x] == false) {
        v = x;
        break;
      }
    }
    if (v == -1) continue;
    Mp[u] = Mp[v] = true;
    sum++;
    Ans[0].push_back(A[u]), Ans[2].push_back(A[v]);
    c--;
    if (sum == mid) return true;
  }
  return false;
}

void solve() {
  for (int i = 1; i <= N; ++i) {
    int cnt = countVowel(A[i]), lst = getLastVowel(A[i]);
//    cout << A[i] << " " << cnt << " " << lst << endl;
    Vowel[cnt].push_back(i);
    LastVow[cnt][lst].push_back(i);
  }

  int lbound = 1, rbound = N / 4, ans = 0;
  while (lbound <= rbound) {
    int mid = (lbound + rbound) >> 1;
    if (check(mid) == true) {
      ans = mid;
      lbound = mid + 1;
    } else rbound = mid - 1;
  }
  printf("%d\n", ans);
  if (ans == 0) return;
  check(ans);
  for (int i = 0; i < ans; ++i) {
    cout << Ans[0][i] << " " << Ans[1][i] << endl;
    cout << Ans[2][i] << " " << Ans[3][i] << endl;
  }
}

int main() {
  init();
  solve();
  return 0;
}