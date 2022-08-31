/**
 *    author:  tourist
 *    created: 19.01.2020 17:31:17       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s(n, '?');
    auto Ask = [&](string t) {
      cout << "? " << t << endl;
      int foo;
      cin >> foo;
      for (int i = 0; i < foo; i++) {
        int bar;
        cin >> bar;
        --bar;
        for (int j = 0; j < (int) t.size(); j++) {
          s[bar + j] = t[j];
        }
      }
    };
    if (n <= 7) {
      Ask("CH");
      Ask("CO");
      if (s == string(n, '?')) {
        if (n == 4) {
          Ask("HO");
          if (s == string(n, '?')) {
            Ask("OH");
            if (s == string(n, '?')) {
              Ask("CCC");
              if (s == string(n, '?')) {
                Ask("OOO");
                if (s[0] == 'O') {
                  if (s[n - 1] == '?') s[n - 1] = 'C';
                } else {
                  Ask("HHH");
                  if (s[0] == 'H') {
                    if (s[n - 1] == '?') s[n - 1] = 'C';
                  } else {
                    Ask("OOCC");
                    if (s == string(n, '?')) s = "HHCC";
                  }
                }
              } else {
                Ask("HCCC");
                Ask("OCCC");
              }
            } else {
              for (int i = 0; i < n; i++) {
                if (s[i] == '?') {
                  s[i] = 'O';
                } else {
                  break;
                }
              }
              goto haha;
            }
          } else {
            goto haha;
          }
        } else {
          Ask("CC");
          if (s[1] != '?' && s[0] == '?') {
            string q = s;
            q[0] = 'H';
            Ask(q);
            if (s[0] == '?') {
              s[0] = 'O';
            }
          } else {
            Ask("OH");
            Ask("HO");
            if (s == string(n, '?')) {
              Ask(string(n, 'H'));
              Ask(string(n, 'O'));
              if (s == string(n, '?')) {
                string q(n, 'H');
                q[n - 1] = 'C';
                Ask(q);
                if (s == string(n, '?')) {
                  s = string(n, 'O');
                  s[n - 1] = 'C';
                }
              }
            } else {
              if (s[n - 1] == 'C' && s.find("H") == string::npos && s.find("O") == string::npos) {
                string q = s;
                for (int i = 0; i < n; i++) {
                  if (q[i] == '?') {
                    q[i] = 'H';
                  }
                }
                Ask(q);
                if (s[0] == '?') {
                  for (int i = 0; i < n; i++) {
                    if (s[i] == '?') {
                      s[i] = 'O';
                    }
                  }
                }
              } else {
                int beg = 0;
                while (beg < n) {
                  if (s[beg] != '?') {
                    ++beg;
                    continue;
                  }
                  int end = beg;
                  while (end + 1 < n && s[end + 1] == '?') {
                    ++end;
                  }
                  if (beg == 0) {
                    for (int i = beg; i <= end; i++) {
                      s[i] = s[end + 1];
                    }
                  } else {
                    for (int i = beg; i <= end; i++) {
                      s[i] = s[beg - 1];
                    }
                  }
                  beg = end + 1;
                }
                string q = s;
                q[n - 1] = 'C';
                Ask(q);
              }
            }
          }
        }
      } else {
        haha:
        while (true) {
          bool any = false;
          for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
              any = true;
              break;
            }
          }
          if (!any) {
            break;
          }
          bool found = false;
          for (int i = 0; i + 4 < n; i++) {
            if (s[i] == '?' && s[i + 1] != '?' && s[i + 2] != '?' && s[i + 3] != '?' && s[i + 4] != '?') {
              string q = "C";
              q += s[i + 1];
              q += s[i + 2];
              q += s[i + 3];
              q += s[i + 4];
              Ask(q);
              if (s[i] == '?') {
                q[0] = 'O';
                Ask(q);
                if (s[i] == '?') {
                  s[i] = 'H';
                }
              }
              found = true;
              break;
            }
          }
          if (found) continue;
          for (int i = 0; i + 4 < n; i++) {
            if (s[i] != '?' && s[i + 1] != '?' && s[i + 2] != '?' && s[i + 3] != '?' && s[i + 4] == '?') {
              string q = "";
              q += s[i];
              q += s[i + 1];
              q += s[i + 2];
              q += s[i + 3];
              q += "C";
              Ask(q);
              if (s[i + 4] == '?') {
                q[4] = 'O';
                Ask(q);
                if (s[i + 4] == '?') {
                  s[i + 4] = 'H';
                }
              }
              found = true;
              break;
            }
          }
          if (found) continue;
          for (int i = 0; i + 3 < n; i++) {
            if (s[i] == '?' && s[i + 1] != '?' && s[i + 2] != '?' && s[i + 3] != '?') {
              string q = "C";
              q += s[i + 1];
              q += s[i + 2];
              q += s[i + 3];
              Ask(q);
              if (s[i] == '?') {
                q[0] = 'O';
                Ask(q);
                if (s[i] == '?') {
                  s[i] = 'H';
                }
              }
              found = true;
              break;
            }
          }
          if (found) continue;
          for (int i = 0; i + 3 < n; i++) {
            if (s[i] != '?' && s[i + 1] != '?' && s[i + 2] != '?' && s[i + 3] == '?') {
              string q = "";
              q += s[i];
              q += s[i + 1];
              q += s[i + 2];
              q += "C";
              Ask(q);
              if (s[i + 3] == '?') {
                q[3] = 'O';
                Ask(q);
                if (s[i + 3] == '?') {
                  s[i + 3] = 'H';
                }
              }
              found = true;
              break;
            }
          }
          if (found) continue;
          for (int i = 0; i + 2 < n; i++) {
            if (s[i] == '?' && s[i + 1] != '?' && s[i + 2] != '?') {
              string q = "C";
              q += s[i + 1];
              q += s[i + 2];
              Ask(q);
              if (s[i] == '?') {
                q[0] = 'O';
                Ask(q);
                if (s[i] == '?') {
                  s[i] = 'H';
                }
              }
              found = true;
              break;
            }
          }
          if (found) continue;
          for (int i = 0; i + 2 < n; i++) {
            if (s[i] != '?' && s[i + 1] != '?' && s[i + 2] == '?') {
              string q = "";
              q += s[i];
              q += s[i + 1];
              q += "C";
              Ask(q);
              if (s[i + 2] == '?') {
                q[2] = 'O';
                Ask(q);
                if (s[i + 2] == '?') {
                  s[i + 2] = 'H';
                }
              }
              found = true;
              break;
            }
          }
          assert(found);
        }
      }
    } else {
      Ask("CH");
      Ask("CO");
      Ask("HC");
      Ask("HO");
      Ask("OC");
      if (s == string(n, '?')) {
        Ask(string(n, 'C'));
        if (s == string(n, '?')) {
          Ask("OHH");
          if (s == string(n, '?')) {
            Ask(string(n - 1, 'O'));
            if (s == string(n, '?')) {
              s = string(n, 'H');
            } else {
              if (s[n - 1] == '?') {
                s[n - 1] = 'H';
              }
            }
          } else {
            for (int i = 0; i < n; i++) {
              if (s[i] == '?') {
                s[i] = 'O';
              } else {
                break;
              }
            }
            for (int i = n - 1; i >= 0; i--) {
              if (s[i] == '?') {
                s[i] = 'H';
              } else {
                break;
              }
            }
          }
        }
      } else {
        Ask("OHH");
        int pref = 0, suf = 0;
        int beg = 0;
        while (beg < n) {
          if (s[beg] != '?') {
            ++beg;
            continue;
          }
          int end = beg;
          while (end + 1 < n && s[end + 1] == '?') {
            ++end;
          }
          if (beg == 0) {
            if (s[end + 1] != 'H') {
              for (int i = beg; i <= end; i++) {
                s[i] = s[end + 1];
              }
            } else {
              pref = end + 1;
            }
          } else {
            if (end == n - 1) {
              if (s[beg - 1] != 'O') {
                for (int i = beg; i <= end; i++) {
                  s[i] = s[beg - 1];
                }
              } else {
                for (int i = beg; i <= end - 1; i++) {
                  s[i] = 'O';
                }
                suf = 1;
              }
            } else {
              if (s[beg - 1] == 'O' && s[end + 1] == 'H') {
                for (int i = beg; i <= end; i++) {
                  s[i] = 'O';
                }
              } else {
                assert(s[beg - 1] == s[end + 1]);
                for (int i = beg; i <= end; i++) {
                  s[i] = s[beg - 1];
                }
              }
            }
          }
          beg = end + 1;
        }
        if (pref > 0) {
          string q = s;
          if (suf > 0) {
            q.pop_back();
          }
          for (int i = 0; i < pref; i++) {
            q[i] = 'O';
          }
          Ask(q);
          if (s[0] == '?') {
            for (int i = 0; i < pref; i++) {
              s[i] = 'H';
            }
          }
        }
        if (suf > 0) {
          string q = s;
          q[n - 1] = 'O';
          Ask(q);
          if (s[n - 1] == '?') {
            s[n - 1] = 'H';
          }
        }
      }
    }
    cout << "! " << s << endl;
    int foo;
    cin >> foo;
    if (foo == 0) break;
  }
  return 0;
}