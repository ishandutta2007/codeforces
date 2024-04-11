#include <iostream>
using namespace std;

struct Trie {
  Trie *ch[2];
  int cnt;
  Trie() {
    ch[0] = NULL;
    ch[1] = NULL;
    cnt = 0;
  }
} *trie;

char c;
int q, v;

void insert(Trie*&, int, int);
void remove(Trie*&, int, int);
int query(Trie*, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  trie = new Trie();
  insert(trie, 0, 30);
  cin >> q;
  while (q--) {
    cin >> c >> v;
    if (c == '+') insert(trie, v, 30);
    if (c == '-') remove(trie, v, 30);
    if (c == '?') cout << query(trie, v, 30) << '\n';
  }
  return 0;
}

void insert(Trie*& trie, int v, int dep) {
  if (dep < 0) return;
  if (!trie->ch[(v & (1 << dep)) ? 1 : 0]) trie->ch[(v & (1 << dep)) ? 1 : 0] = new Trie();
  trie->ch[(v & (1 << dep)) ? 1 : 0]->cnt++;
  insert(trie->ch[(v & (1 << dep)) ? 1 : 0], v, dep - 1);
}

void remove(Trie*& trie, int v, int dep) {
  if (dep < 0) return;
  trie->ch[(v & (1 << dep)) ? 1 : 0]->cnt--;
  remove(trie->ch[(v & (1 << dep)) ? 1 : 0], v, dep - 1);
  // if (trie->ch[(v & (1 << dep)) ? 1 : 0]->cnt <= 0) delete trie;
}

int query(Trie* trie, int v, int dep) {
  if (dep < 0) return 0;
  if (trie->ch[(v & (1 << dep)) ? 0 : 1] && trie->ch[(v & (1 << dep)) ? 0 : 1]->cnt > 0)
    return (1 << dep) + query(trie->ch[(v & (1 << dep)) ? 0 : 1], v, dep - 1);
  else return query(trie->ch[(v & (1 << dep)) ? 1 : 0], v, dep - 1);
}