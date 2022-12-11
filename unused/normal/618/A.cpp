#include <stdio.h>
#include <vector>
using namespace std;

vector<int> vt;

int main()
{
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    vt.push_back(1);
    while (vt.size() >= 2)
    {
      if (vt[vt.size() - 1] == vt[vt.size() - 2])
      {
        int t = vt.back();
        vt.pop_back();
        vt.pop_back();
        vt.push_back(t + 1);
      }
      else break;
    }
  }

  for (int t : vt) printf("%d ", t);
}