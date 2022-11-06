#include <bits/stdc++.h>
using namespace std;

int a, b, c, m, v, equiped;
long long tot;
vector<int> ps2, usb, lft;
string s;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> a >> b >> c;
  cin >> m;
  while (m--) {
    cin >> v >> s;
    if (s == "PS/2") ps2.push_back(v);
    else usb.push_back(v);
  }
  sort(ps2.begin(), ps2.end());
  sort(usb.begin(), usb.end());
  int ui = 0, pi = 0;
  for (int i = 0; i < a && ui < usb.size(); ++i) equiped++, tot += usb[ui++];
  for (int i = 0; i < b && pi < ps2.size(); ++i) equiped++, tot += ps2[pi++];
  for (; ui < usb.size(); ++ui) lft.push_back(usb[ui]);
  for (; pi < ps2.size(); ++pi) lft.push_back(ps2[pi]);
  sort(lft.begin(), lft.end());
  int li = 0;
  for (; c && li < lft.size(); ++li) equiped++, tot += lft[li], --c;
  cout << equiped << ' ' << tot << '\n';
  return 0;
}