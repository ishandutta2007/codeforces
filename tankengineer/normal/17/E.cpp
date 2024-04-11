//17E
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int n, cur_center, cur_right, cur_left, old_center, par_len[4000005] = {}, t1, t2, t3, str[2000005] = {}, fin[2000005] = {};
long long ans, sum, lans;
string s;

int main() {
  cin >> n >> s;
  n = s.size();
  cur_center = 1;
  cur_right = 1;
  while (cur_center < 2 * n + 1) {
    cur_left = cur_center * 2 - cur_right;
    while (cur_left >= 1 && (cur_right % 2 ? 0 : s[cur_right / 2 - 1]) == (cur_left % 2 ? 0 : s[cur_left / 2 - 1])) {
      cur_left--; cur_right++;
    }
    par_len[cur_center] = 2 * (cur_right - cur_center) - 1;
    cur_center++;
    cur_left++;
    old_center = cur_center - 2;
    while (old_center >= 1 && cur_center <= 2 * n + 1) {
      if ((old_center - (par_len[old_center] + 1) / 2) > cur_left || cur_right == 2 * n + 1) {
        par_len[cur_center] = par_len[old_center];
        cur_center++; old_center--;
      } else {
        break;
      }
    }
  }
  
  lans = 0;
  
  for (int i = 1; i <= 2 * n + 1; i++) {
    if (i % 2 == 0) {
      t1 = (i - (par_len[i] + 1) / 2 + 2) / 2 - 1;
      t3 = i / 2 - 1;
      t2 = (i + (par_len[i] + 1) / 2 - 2) / 2 - 1;
      if (t1 < 0 || t2 < 0 || t1 > t2) continue;
      str[t1]++; str[t3 + 1]--;
      fin[t3 - 1]--; fin[t2]++;
    } else {
      t1 = (i - par_len[i] / 2 + 1) / 2 - 1;
      t2 = (i + par_len[i] / 2 - 1) / 2 - 1;
      t3 = i / 2;
      if (t1 < 0 || t2 < 0 || t1 > t2) continue;
      str[t1]++; str[t3]--;
      fin[t3 - 1]--; fin[t2]++;
    }
  }
  for (int i = 1; i <= n; i++) str[i] += str[i - 1];
  for (int i = n - 1; i >= 0; i--) fin[i] += fin[i + 1];
  for (int i = 0; i < n; i++) {
    lans += str[i];
  }
  
  lans = lans % 51123987;
  lans = (lans * (lans - 1)) / 2;
  
  ans = 0;
  sum = 0;
  for (int i = 0; i <= n; i++) {
    ans = (ans + sum * str[i]) % 51123987;
    sum = (sum + fin[i]) % 51123987;
  }
  
  lans -= ans;
  lans = lans % 51123987;
  if (lans < 0) lans += 51123987;
  
  cout << lans << endl;
  return 0;
}