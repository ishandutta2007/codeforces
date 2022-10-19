#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, x, y;

typedef double db;
const db eps = 1e-12;

double A[N];

struct NODE {
  int x;
  db bef, now;
  friend bool operator < (NODE a, NODE b) {
	return a.bef * b.now > a.now * b.bef;
  }
};

priority_queue <NODE> q;

main() {
  cin >> n;
  db who = 1;
  for(int i = 1; i <= n; ++ i) {
	scanf("%d", &x);
	A[i] = 1 - (db)x / 100;
	q.push((NODE){i, 1 - A[i], 1 - A[i] * A[i]});
	who = who * (1 - A[i]);
  }
  int cnt = n;
  db ans = 0;
  ans += cnt * who;
  //cerr << who << endl;
  for(int i = cnt + 1; i <= 5e5; ++ i) {
	NODE now = q.top();
	q.pop();
	//if(i <= 10) cerr <<i << " " << who << endl;
	ans = ans + (who / now.bef * now.now - who) * i;
	who = who / now.bef * now.now;
	//if(i <= 10)cerr << now.x << " " << now.now <<" " << 1 - (1 - now.now) * A[now.x] << endl;
	q.push((NODE){now.x, now.now, 1 - (1 - now.now) * A[now.x]});
  }
  printf("%.12lf\n", ans);
}