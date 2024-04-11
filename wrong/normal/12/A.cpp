#include<cstdio>

using namespace std;

int main()
{
  char s[3][4];
  for(int i=0; i<3; ++i)
    scanf("%s", s[i]);
  bool ok = true;
  for(int i=0; i<3; ++i)
    for(int j=0; j<3; ++j)
      if(s[i][j] != s[2-i][2-j])
	ok = false;
  puts(ok ? "YES" : "NO");
  return 0;
}