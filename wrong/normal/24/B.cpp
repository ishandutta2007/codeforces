#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct racer {
  string name;
  int point;
  vector<int> place;
  racer() : name(""), point(0), place(50, 0) { }
};

bool cmp1(const racer& a, const racer& b)
{
  if(a.point != b.point) return a.point < b.point;
  else return a.place < b.place;
}

bool cmp2(const racer& a, const racer& b)
{
  if(a.place[0] != b.place[0]) return a.place[0] < b.place[0];
  else if(a.point != b.point) return a.point < b.point;
  else return a.place < b.place;
}

int pts[] = {25,18,15,12,10,8,6,4,2,1};

int main()
{
  int t;
  scanf("%d", &t);
  map<string, racer> R;
  for(int i=0; i<t; ++i) {
    int n;
    scanf("%d", &n);
    for(int j=0; j<n; ++j) {
      char s[64];
      scanf("%s", s);
      string nm = s;
      if(R.find(nm) == R.end())
	R[nm].name = nm;
      if(j < 10) R[nm].point += pts[j];
      R[nm].place[j]++;
    }
  }
  vector<racer> v;
  for(map<string,racer>::iterator it=R.begin();it!=R.end();++it)
    v.push_back(it->second);
  sort(v.begin(), v.end(), cmp1);
  printf("%s\n", v.back().name.c_str());
  sort(v.begin(), v.end(), cmp2);
  printf("%s\n", v.back().name.c_str());
  return 0;
}