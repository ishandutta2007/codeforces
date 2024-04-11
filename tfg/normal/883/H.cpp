#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;
int mp[300];
int at;

void makePal(string &s) {
  int n = s.size();
  if (n&1) {
    int ch;
    fr(i, 0, 256) {
      if (mp[i] > 0) {
        ch = i;
      }
      if (mp[i]&1) {
        break;
      }
    }
    s[n/2] = ch;
    mp[ch]--;
  }
  int i = 0, j = n-1;
  while (i < j) {
    while (mp[at] <= 1) at++;
    s[i] = at;
    s[j] = at;
    i++;
    j--;
    mp[at] -= 2;
  }
}

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  for (char ch : s) {
    mp[ch]++;
  }
  int cnt = 0;
  fr(i, 0, 300) {
    cnt += mp[i] & 1;
  }
  if (cnt <= 1) {
    string s(n, ' ');
    makePal(s);
    puts("1");
    cout << s << endl;
    return 0;
  }
  int qt;
  fr(i, 1, n+1) {
    if (n % i != 0)
      continue;
    if (i < cnt)
      continue;
    if (!((n / i) & 1))
      continue;
    if ((cnt - i)&1)
      continue;
    qt = i;
    break;
  }
  int sz = n / qt;
  string aux(sz, ' ');
  cout << qt << endl;
  fr(eae, 0, qt) {
    makePal(aux);
    if (eae) {
      cout << ' ';
    }
    cout << aux;
  }
  cout << endl;
}