#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int p[N];
int cnt[N];
int my[N];

inline pair <int, int> get_pair(int i, int my) {
  if (my < 0) {
    return make_pair(0, 1);
  }
  if (my > cnt[i]) {
    return make_pair(p[i], 2);
  }
  return make_pair(p[i] * my, my + cnt[i]);
}

inline double get_double(int i, int my) {
  pair <int, int> z = get_pair(i, my);
  return z.first * 1.0 / z.second;
}

struct Profit {
  int id;
  int my;
  long long pa;
  long long pb;
  double profit;

  Profit(int id, int my) {
    this->id = id;
    this->my = my;
    if (my == 0) {
      this->pa = 1;
      this->pb = 0;
    } else {
      if (my <= cnt[id]) {
        this->pa = p[id] * cnt[id];
        this->pb = (my + cnt[id]) * 1LL * (my + cnt[id] - 1);
      } else {
        this->pa = 0;
        this->pb = 1;
      }
    }
    this->profit = this->pa * 1.0 / this->pb;
  }
};

struct better_first {
  bool operator() (const Profit &thiss, const Profit &other) {
    long long diff = thiss.pa * other.pb - thiss.pb * other.pa;
    if (diff != 0) {
      return diff > 0;
    }
    if (thiss.id != other.id) {
      return thiss.id > other.id;
    }
    return thiss.my > other.my;
  }
};

struct worse_first {
  bool operator() (const Profit &thiss, const Profit &other) {
    long long diff = thiss.pa * other.pb - thiss.pb * other.pa;
    if (diff != 0) {
      return diff < 0;
    }
    if (thiss.id != other.id) {
      return thiss.id < other.id;
    }
    return thiss.my < other.my;
  }
};


/*  bool operator <(const Profit &other) const {
    long long diff = this.pa * other.pb - this.pb * other.pa;
    if (diff != 0) {
      return diff < 0;
    }
    if (id != other.id) {
      return id < other.id;
    }
    return my < other.my;
  }*/

int main() {
  int n, have, q;
  scanf("%d %d %d", &n, &have, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", cnt + i);
  }
  for (int i = 0; i < n; i++) {
    my[i] = 0;
  }
  set <Profit, better_first> nxt;
  for (int i = 0; i < n; i++) {
    nxt.insert(Profit(i, 1));
  }
  double res = 0.0;
  while (have > 0 && !nxt.empty()) {
    have--;
    Profit z = *(nxt.begin());
    nxt.erase(nxt.begin());
    int i = z.id;
    res += z.profit;
    my[i]++;
    if (my[i] < cnt[i]) {
      nxt.insert(Profit(i, my[i] + 1));
    }
  }
  set <Profit, worse_first> lst;
  for (int i = 0; i < n; i++) {
    if (my[i] > 0) {
      lst.insert(Profit(i, my[i]));
    }
  }
  while (q--) {
    int type, id;
    scanf("%d %d", &type, &id);
    id--;
    if (my[id] < cnt[id]) {
      nxt.erase(Profit(id, my[id] + 1));
    }
    if (my[id] > 0) {
      lst.erase(Profit(id, my[id]));
    }
    if (type == 1) {
      if (have > 0) {
        cnt[id]++;
        my[id]++;
        have--;
      } else {
        res -= p[id] * my[id] * 1.0 / (my[id] + cnt[id]);
        cnt[id]++;
        res += p[id] * my[id] * 1.0 / (my[id] + cnt[id]);
        while (my[id] > 0 && !nxt.empty()) {
          Profit cur = Profit(id, my[id]);
          Profit best = *(nxt.begin());
          if (cur.profit < best.profit) {
            int rm = best.id;
            if (my[rm] < cnt[rm]) {
              nxt.erase(Profit(rm, my[rm] + 1));
            }
            if (my[rm] > 0) {
              lst.erase(Profit(rm, my[rm]));
            }
            res += best.profit;
            my[rm]++;
            if (my[rm] < cnt[rm]) {
              nxt.insert(Profit(rm, my[rm] + 1));
            }
            if (my[rm] > 0) {
              lst.insert(Profit(rm, my[rm]));
            }
            res -= cur.profit;
            my[id]--;
          } else {
            break;
          }
        }
        while (my[id] < cnt[id] && !lst.empty()) {
          Profit cur = Profit(id, my[id] + 1);
          Profit worst = *(lst.begin());
          if (cur.profit > worst.profit) {
            int rm = worst.id;
            if (my[rm] < cnt[rm]) {
              nxt.erase(Profit(rm, my[rm] + 1));
            }
            if (my[rm] > 0) {
              lst.erase(Profit(rm, my[rm]));
            }
            res -= worst.profit;
            my[rm]--;
            if (my[rm] < cnt[rm]) {
              nxt.insert(Profit(rm, my[rm] + 1));
            }
            if (my[rm] > 0) {
              lst.insert(Profit(rm, my[rm]));
            }
            res += cur.profit;
            my[id]++;
          } else {
            break;
          }
        }
      }
      if (my[id] < cnt[id]) {
        nxt.insert(Profit(id, my[id] + 1));
      }
      if (my[id] > 0) {
        lst.insert(Profit(id, my[id]));
      }
    } else {
      if (my[id] == cnt[id]) {
        cnt[id]--;
        my[id]--;
        if (!nxt.empty()) {
          Profit z = *(nxt.begin());
          nxt.erase(nxt.begin());
          int i = z.id;
          if (my[i] < cnt[i]) {
            nxt.erase(Profit(i, my[i] + 1));
          }
          if (my[i] > 0) {
            lst.erase(Profit(i, my[i]));
          }
          res += z.profit;
          my[i]++;
          if (my[i] < cnt[i]) {
            nxt.insert(Profit(i, my[i] + 1));
          }
          if (my[i] > 0) {
            lst.insert(Profit(i, my[i]));
          }
        } else {
          have++;
        }
      } else {
        res -= p[id] * my[id] * 1.0 / (my[id] + cnt[id]);
        cnt[id]--;
        res += p[id] * my[id] * 1.0 / (my[id] + cnt[id]);
        while (my[id] < cnt[id] && !lst.empty()) {
          Profit cur = Profit(id, my[id] + 1);
          Profit worst = *(lst.begin());
          if (cur.profit > worst.profit) {
            int rm = worst.id;
            if (my[rm] < cnt[rm]) {
              nxt.erase(Profit(rm, my[rm] + 1));
            }
            if (my[rm] > 0) {
              lst.erase(Profit(rm, my[rm]));
            }
            res -= worst.profit;
            my[rm]--;
            if (my[rm] < cnt[rm]) {
              nxt.insert(Profit(rm, my[rm] + 1));
            }
            if (my[rm] > 0) {
              lst.insert(Profit(rm, my[rm]));
            }
            res += cur.profit;
            my[id]++;
          } else {
            break;
          }
        }
        while (my[id] > 0 && !nxt.empty()) {
          Profit cur = Profit(id, my[id]);
          Profit best = *(nxt.begin());
          if (cur.profit < best.profit) {
            int rm = best.id;
            if (my[rm] < cnt[rm]) {
              nxt.erase(Profit(rm, my[rm] + 1));
            }
            if (my[rm] > 0) {
              lst.erase(Profit(rm, my[rm]));
            }
            res += best.profit;
            my[rm]++;
            if (my[rm] < cnt[rm]) {
              nxt.insert(Profit(rm, my[rm] + 1));
            }
            if (my[rm] > 0) {
              lst.insert(Profit(rm, my[rm]));
            }
            res -= cur.profit;
            my[id]--;
          } else {
            break;
          }
        }
        if (my[id] < cnt[id]) {
          nxt.insert(Profit(id, my[id] + 1));
        }
        if (my[id] > 0) {
          lst.insert(Profit(id, my[id]));
        }
      }
    }
    printf("%.17f\n", res);
  }
  return 0;
}