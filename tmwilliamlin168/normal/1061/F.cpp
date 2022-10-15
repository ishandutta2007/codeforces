#include <bits/stdc++.h>
#include <chrono>



using namespace std;

using ll = long long;

#define db(x) cerr << #x << " == " << (x) << endl;
//#define db(x)



int n, k;


int ask(int x, int y, int z) {
   cout << "? " << x << ' ' << y << ' ' << z << '\n';
   cout.flush();
   string ans;
   cin >> ans;
   return ans == "Yes";
}

int findNonLeaf() {
   for (int i = 3; i <= n; i++) if (ask(1, i, 2)) return i;
   return ask(1, 2, 3) ? 2 : 1;
}

pair<int, int> go(int x) {
   vector<vector<int>> parts;
   int cnt = 0;
   int last = 0;
   for (int i = 1; i <= n; i++) {
      if (i == x) continue;
      if (++cnt > (n + k) / (k + 1) + 1) break;
      last = i;

      bool done = false;
      for (auto& part : parts) {
         if (not ask(i, x, part.back())) {
            part.push_back(i);
            done = true;
            break;
         }
      }

      if (not done) parts.push_back({i});
   
   }
   vector<int> big;
   for (auto& part : parts) {
      if (part.size() > big.size()) part.swap(big);
   }
   for (int i = last + 1; i <= n; i++)
      if (i != x and not ask(i, x, big.back())) big.push_back(i);
   int y = big.back();
   for (int i : big) {
      if (i == y) continue;
      if (ask(x, i, y)) y = i;
   }
   return {y, int(big.size())};
}

int main() {
   ios::sync_with_stdio(false);
   cin >> n >> k;

   
   int x = findNonLeaf();
   while (k <= 38) {
      int y, cnt;
      tie(y, cnt) = go(x);
      db(y); db(cnt);
      if (cnt * k < n) break;
      x = y;
   }

   cout << "! " << x << endl;
}