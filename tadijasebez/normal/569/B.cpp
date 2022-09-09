#include <bits/stdc++.h>
using namespace std;
static int lim=100050;
int main()
{
      int n;scanf("%i",&n);
      deque<int> work;
      vector<int> cnt(lim,0);
      vector<int> a(n,0);
      for(int i=0;i<n;i++)
      {
            scanf("%i",&a[i]);
            cnt[a[i]]++;
      }
      for(int i=1;i<=n;i++)
      {
            if(cnt[i]==0) work.push_back(i);
      }
      for(int i=0;i<n;i++)
      {
            if(a[i]>n || cnt[a[i]]>1)
            {
                  cnt[a[i]]--;
                  a[i]=work.front();
                  work.pop_front();
            }
      }
      for(int i=0;i<n;i++)
      {
            printf("%i ",a[i]);
      }
      return 0;
}