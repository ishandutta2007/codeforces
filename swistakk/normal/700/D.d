import std.stdio;
import std.algorithm;
import std.container.dlist;

const int N = 100_123;
const int kSqrt = 400;

struct BiList {
  int mult;
  int prv, nxt;
}

struct Query {
  int l, r, id;
}

bool cmp(Query a, Query b) {
  if (a.l / kSqrt != b.l / kSqrt) {
    return a.l < b.l;
  }
  if (a.r == b.r) { return false; }
  return cast(bool)((a.r < b.r) ^ ((a.l / kSqrt) % 2));
}

int[N] ans;
int[N] val;
Query[N] qs;
int[N] cnt_val;
BiList[N] cnts_list;

void EraseFromBi(int prv, int nxt) {
  cnts_list[prv].nxt = nxt;
  cnts_list[nxt].prv = prv;
}

void AddToBi(int ind, int prv, int nxt) {
//   writef("+%d, %d, %d\n", ind, prv, nxt);
  cnts_list[ind].prv = prv;
  cnts_list[ind].nxt = nxt;
  cnts_list[prv].nxt = ind;
  cnts_list[nxt].prv = ind;
}
  
void Modify(int ind, int diff) {
  int v = val[ind];
  int c = cnt_val[v];
  int p = cnts_list[c].prv;
  int r = cnts_list[c].nxt;
  cnts_list[c].mult--;
  if (cnts_list[c].mult == 0) {
    EraseFromBi(p, r);
  }
  c += diff;
  cnt_val[v] += diff;
  if (cnts_list[c].mult == 0) {
    if (diff == 1 && cnts_list[c - 1].mult) {
      p = c - 1;
    }
    if (diff == -1 && cnts_list[c + 1].mult) {
      r = c + 1;
    }
    AddToBi(c, p, r);
  }
  cnts_list[c].mult++;
//   foreach (j; 0 .. 5) {
//     writef("(m: %d, p: %d, n: %d), ", cnts_list[j].mult, cnts_list[j].prv, cnts_list[j].nxt);
//   }
//   writef("\n");
}

void Add(int ind) {
  Modify(ind, 1);
}

void Remove(int ind) {
  Modify(ind, -1);
}

struct Pair {
  int freq, cnt;
}

struct Que {
  Pair[N] q;
  int beg, past_en;
  void Reset() {
    beg = 0;
    past_en = 0;
  }
  bool empty() {
    return beg == past_en;
  }
  void insertBack(Pair p) {
    q[past_en] = p;
    past_en++;
  }
  void insertFront(Pair p) {
    beg--;
    q[beg] = p;
  }
  Pair front() {
    return q[beg];
  }
  Pair back() {
    return q[past_en - 1];
  }
  void removeFront(int a) {
    beg += a;
  }
}

Que too_big, que;

void main() {
  int n;
  readf("%d", &n);
  foreach (i; 1 .. n + 1) {
    readf(" %d", &val[i]);
  }
  int que_num;
  readf(" %d", &que_num);
  foreach (i; 1 .. que_num + 1) {
    readf(" %d %d", &qs[i].l, &qs[i].r);
    qs[i].id = i;
  }
  
  sort!(cmp)(qs[1 .. que_num + 1]);
//   if (val[1] == 52388) {
//     while (1) { val[1] = 3; }
//   }
  int curl = 1, curr = 0;
  cnts_list[0].mult = N;
  
  foreach (i; 1 .. que_num + 1) {
    Query z = qs[i];
    while (curl > z.l) {
      curl--;
      Add(curl);
    }
    while (curr < z.r) {
      curr++;
      Add(curr);
    }
    while (curl < z.l) {
      Remove(curl);
      curl++;
    }
    while (curr > z.r) {
      Remove(curr);
      curr--;
    }
    
    int res = 0;
    too_big.Reset;
    que.Reset;
    int cur = 0;
    do {
      cur = cnts_list[cur].nxt;
      if (cur != 0) {
        too_big.insertBack(Pair(cur, cnts_list[cur].mult));
      }
    } while (cur != 0);
    
    void Transfer(int up_to) {
      if (too_big.empty()) { return; }
      if ((que.empty() && up_to == -1) || too_big.front().freq <= up_to) {
        //writef("%d %d\n", too_big.front().freq, too_big.front().cnt);
        que.insertBack(too_big.front());
        too_big.removeFront(1);
        Transfer(up_to);
      }
    }
    Transfer(-1);
    while (!que.empty()) {
      Pair p = que.front();
      que.removeFront(1);
      if (p.cnt % 2 == 0) {
        res += p.cnt * p.freq;
        Transfer(2 * p.freq);
        que.insertBack(Pair(2 * p.freq, p.cnt / 2));
      } else if (p.cnt == 1) {
        if (que.empty()) { Transfer(-1); }
        if (que.empty()) { break; }
        Pair q = que.front();
        que.removeFront(1);
        res += p.freq + q.freq;
        Transfer(p.freq + q.freq);
        que.insertBack(Pair(p.freq + q.freq, 1));
        if (q.cnt > 1) {
          que.insertFront(Pair(q.freq, q.cnt - 1));
        }
      } else {
        res += (p.cnt - 1) * p.freq;
        Transfer(2 * p.freq);
        que.insertBack(Pair(2 * p.freq, p.cnt / 2));
        que.insertFront(Pair(p.freq, 1));
      }
    }
    ans[qs[i].id] = res;
  }
    
  foreach (i; 1 .. que_num + 1) {
    writef("%d\n", ans[i]);
  }
  
}