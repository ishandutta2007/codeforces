#include <bits/stdc++.h>
using namespace std;

const int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const long long D = 1000000000000LL;

bool leap(long long y) {
  return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}

array<long long, 7> to_date(long long s) {
  long long n, h, w, d, m = 0, y = 1970;
  n = s / 60, s %= 60;
  h = n / 60, n %= 60;
  d = h / 24, h %= 24;
  w = (d + 3) % 7;

  for (y = 1970; 365 + leap(y) <= d; ++y) {
    d -= 365 + leap(y);
  }

  for (m = 0; M[m] + (leap(y) && m == 1) <= d; ++m) {
    d -= M[m] + (leap(y) && m == 1);
  }

  return {s, n, h, w, d, m, y};
}

long long to_seconds(array<long long, 7> date) {
  auto [s, n, h, w, d, m, y] = date;
  for (--m; m >= 0; --m) {
    d += M[m] + (leap(y) && m == 1);
  }

  for (--y; y >= 1970; --y) {
    d += 365 + leap(y);
  }

  h += 24 * d;
  n += 60 * h;
  s += 60 * n;
  return s;
}

void nxt_day(array<long long, 7> &date) {
  auto &[s, n, h, w, d, m, y] = date;
  w = (w + 1) % 7;
  if (++d == M[m] + (leap(y) && m == 1)) {
    d = 0;
    if (++m == 12) {
      m = 0, ++y;
    }
  }
}

void nxt_second(array<long long, 7> &date) {
  auto &[s, n, h, w, d, m, y] = date;
  if (++s == 60) {
    s = 0;
    if (++n == 60) {
      n = 0;
      if (++h == 24) {
        h = 0;
        nxt_day(date);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long ts, tn, th, tw, td, tm;
  cin >> ts >> tn >> th >> tw >> td >> tm;

  tw -= (tw > 0);
  td -= (td > 0);
  tm -= (tm > 0);

  int q;
  cin >> q;
  while (q--) {
    long long t;
    cin >> t;
    array<long long, 7> date = to_date(++t);
    auto &[s, n, h, w, d, m, y] = date;

    while ((ts != -1 && s != ts) || (tn != -1 && n != tn) || (th != -1 && h != th)) {
      nxt_second(date);
    }

    bool tomorrow = false;
    while ((tw != -1 && td != -1 && w != tw && d != td) || (tm != -1 && m != tm) ||
        (tw != -1 && td == -1 && w != tw) || (tw == -1 && td != -1 && d != td)) {
      tomorrow = true;
      nxt_day(date);
    }

    if (tomorrow) {
      s = 0, n = 0, h = 0;
      while ((ts != -1 && s != ts) || (tn != -1 && n != tn) || (th != -1 && h != th)) {
        nxt_second(date);
      }
    }

    cout << to_seconds(date) << "\n";
  }
}