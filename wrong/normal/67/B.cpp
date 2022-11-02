#include<cstdio>
#include<list>

int main()
{
  int n, k, b[1024];
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; ++i) scanf("%d", &b[i]);
  std::list<int> a;
  for(int i=n-1; i>=0; --i) {
    int x = 0;
    if(b[i]==0) { a.push_front(i+1); continue; }
    for(std::list<int>::iterator it=a.begin(); it!=a.end(); ++it) {
      if(*it>=i+k+1) x++;
      if(b[i]==x) {
	it++;
	a.insert(it, i+1);
	break;
      }
    }
  }
  for(std::list<int>::iterator it=a.begin(); it!=a.end(); ++it)
    printf("%d ", *it);
  puts("");
  return 0;
}