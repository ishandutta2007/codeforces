#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, l, k1;
string s;
vector<long long> gr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    cin >> n >> s;
    l = 1;
    for (i = 0; i < n - 1; i++) {
      if (s[i] == '>') {
        gr.push_back(l);
        l = 1;
      } else {
        l++;
      }
    }
    gr.push_back(l);
    k = n + 1;
    for (i = 0; i < gr.size(); i++) {
      k = k - gr[i];
      k1 = k;
      for (j = 0; j < gr[i]; j++) {
        cout << k1 << ' ';
        k1++;
      }
    }
    cout << endl;
    gr.clear();
    l = 1;
    for (i = 0; i < n - 1; i++) {
      if (s[i] == '<') {
        gr.push_back(l);
        l = 1;
      } else {
        l++;
      }
    }
    gr.push_back(l);
    k = 0;
    for (i = 0; i < gr.size(); i++) {
      k = k + gr[i];
      k1 = k;
      for (j = 0; j < gr[i]; j++) {
        cout << k1 << ' ';
        k1--;
      }
    }
    cout << endl;
    gr.clear();
  }

  return 0;
}