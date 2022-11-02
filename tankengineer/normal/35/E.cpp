#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

const int N = 100005 * 4;

int n, t1, t2, t3, top, times[N], event[N], ord[N], old_ans, new_ans, anst, x[N], y1[N], y2[N];
multiset<int> tr;

bool cmp(int i, int j) {return times[i] < times[j] || times[i] == times[j] && event[i] > event[j];}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", &t1, &t2, &t3);
    ++top; times[top] = t2; event[top] = t1; ord[top] = top;
    ++top; times[top] = t3; event[top] = -t1; ord[top] = top;
  }
  tr.insert(0);
  times[0] = -1000000007;
  times[top + 1] = -1000000007;
  old_ans = 0;
  sort(ord + 1, ord + top + 1, cmp);
  for (int i = 1; i <= top; ++i) {
    if (event[ord[i]] > 0) tr.insert(event[ord[i]]); else tr.erase(tr.find(-event[ord[i]]));
    new_ans = *tr.rbegin();
    if (times[ord[i]] != times[ord[i + 1]] && new_ans != old_ans) {
      ++anst; x[anst] = times[ord[i]]; y1[anst] = old_ans; y2[anst] = new_ans;
      old_ans = new_ans;
    }
  }
  printf("%d\n", anst * 2);
  for (int i = 1; i <= anst; ++i) printf("%d %d\n%d %d\n", x[i], y1[i], x[i], y2[i]);
  return 0;
}