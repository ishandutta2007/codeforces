#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  const char *C[] = {"Carrots", "Kiwis", "Grapes"};
  int n, m, k, t;
  vector<pair<int, int> > w;
  scanf("%d%d%d%d", &n, &m, &k, &t);
  for(int i=0; i<k; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    w.push_back(make_pair(a, b));
  }
  sort(w.begin(), w.end());
  for(int i=0; i<t; ++i) {
    int a, b, c;
    scanf("%d%d", &a, &b);
    c = lower_bound(w.begin(), w.end(), make_pair(a, b)) - w.begin();
    if(0<=c && c<(int)w.size() && w[c]==make_pair(a, b)) {
      puts("Waste");
    } else {
      puts(C[((a-1)*m+b-1-c)%3]);
    }
  }
  return 0;
}