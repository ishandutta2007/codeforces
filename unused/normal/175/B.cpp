#include <bits/stdc++.h>
using namespace std;

map<string, int> score;

int main()
{
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    char name[15];
    int s;
    scanf("%s%d",name,&s);
    score[name] = max(score[name], s);
  }

  n = score.size();
  printf("%d\n", n);

  for (auto &e : score)
  {
    int better = 0;
    for (auto &j : score)
    {
      if (e.second < j.second) ++better;
    }

    printf("%s ", e.first.c_str());

    if (better * 2 > n) printf("noob\n");
    else if (better * 5 > n) printf("random\n");
    else if (better * 10 > n) printf("average\n");
    else if (better * 100 > n) printf("hardcore\n");
    else printf("pro\n");
  }
}