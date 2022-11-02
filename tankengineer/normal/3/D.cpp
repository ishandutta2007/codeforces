//CF 3D
#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;
priority_queue<pair<int, int> > q;
pair<int, int> t;
int t1, t2;
long long c, ans;
string s;
int main() {
  cin>>s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      c++;
    } else if (s[i] == ')') {
      c--;
    } else{
      s[i] = ')';
      c--;
      scanf("%d %d", &t1, &t2);
      ans += t2;
      q.push(make_pair(t2 - t1, i));
    }
    if (c < 0) {
      if (q.empty()) break;
      t = q.top();
      q.pop();
      c += 2;
      s[t.second] = '(';
      ans -= t.first;
    }
  }
  
  if (c != 0) {
    printf("-1\n");
  } else {
    printf("%I64d\n", ans);
    cout<<s<<endl;
  }
  
  return 0;
}