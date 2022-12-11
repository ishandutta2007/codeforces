#include <bits/stdc++.h>
using namespace std;

set<pair<long long,long long>> st;

int main()
{
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    long long a,b;
    scanf("%lld%lld",&a,&b);

    bool wrong = false;
    for (auto &&e : st)
    {
      if (e.second<a) continue;
      if (e.first>a+b-1) continue;
      wrong = true; break;
    }

    if (wrong == false)
    {
      st.emplace(a,a+b-1);
      printf("%lld %lld\n", a, a+b-1);
      continue;
    }

    long long last = 0;

    for (auto &&e : st)
    {
      if (e.first - last >= b + 1)
      {
        break;
      }

      last = e.second;
    }

    st.emplace(last + 1, last + b);
    printf("%lld %lld\n", last + 1, last + b);
  }
}