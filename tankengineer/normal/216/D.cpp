//d
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100005;
int n, top, m[N], st[N], ans, getans[N][2], t[N];

inline int lowbit(const int i) {return (i & (-i));}

int sum(int i) {
  int s = 0, l = i;
	while (l) {
	  s += t[l];
		l -= lowbit(l);
	}
	return s;
}

void changes(const int pos, const int delta) {
  int p = pos;
	while (p <= 100000) {
	  t[p] += delta;
		p += lowbit(p);
	}
}

void change(const int i, const int delta) {
  //printf("changing %d %d\n", i, delta);
  for (int j = m[i - 1] + 1; j <= m[i]; ++j) {
    changes(st[j], delta);
  }
}

void ask(const int i, const int pos) {
  //printf("asking %d %d\n", i, pos);
  for (int j = m[i - 1] + 2; j <= m[i]; ++j) {
    getans[j][pos] = sum(st[j]) - sum(st[j - 1]);
    //printf("%d : %d   %d : %d\n", st[j], sum(st[j]), st[j - 1], sum(st[j - 1]));
  }
}

int main() {
  scanf("%d", &n);
  top = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &m[i]);
    int t1 = top;
    for (int j = 1; j <= m[i]; ++j) {
      scanf("%d", &st[++top]);
    }
    sort(st + t1 + 1, st + top + 1);
    m[i] += m[i - 1];
  }
  change(1, 1);
  for (int i = 2; i <= n; ++i) {
    ask(i, 0);
    change(i - 1, -1);
    change(i, 1);
  }
  ask(1, 0);
  for (int i = n - 1; i >= 1; --i) {
    ask(i, 1);
    change(i + 1, -1);
    change(i, 1);
  }
  ask(n, 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = m[i - 1] + 2; j <= m[i]; ++j) {
      //printf("%d %d - %d : %d / %d\n", i, st[j - 1], st[j], getans[j][0], getans[j][1]);
      if (getans[j][0] != getans[j][1]) ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}