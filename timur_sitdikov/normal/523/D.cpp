#include <queue>
#include <vector>
#include <cstdio>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

int n, k;
void get(int& a) {
 scanf("%d",&a);
}

typedef pair<long long, int> type;
priority_queue<type, vector<type>, greater<type> > q;

vector<long long> answer;

int main () {

 get(n);
 get(k);
 
 for (int i = 0; i < k; ++i) {
  q.push(make_pair(0, -1));
 }  

 answer.resize(n);
 
 int s, m;
 type cur;

 for (int i = 0; i < n; ++i) {
  get(s);
  get(m);
  cur = q.top();
  q.pop();
  if (cur.second != -1) {
   answer[cur.second] = cur.first;
  }
  cur.first = max(cur.first, (long long)s) + (long long)m;
  cur.second = i;
  q.push(cur);
 }

 while (!q.empty()) {
  cur = q.top();
  q.pop();
  if (cur.second != -1) {
   answer[cur.second] = cur.first;
  }
 }
 for (int i = 0; i < n ; ++i ){
  printf("%I64d\n", answer[i]);  
 }

 return 0;
}