#include<cstdio>
#include<vector>

using namespace std;

int isp[1024];
vector<int> er(int n)
{
  for(int i=2; i<1024; ++i) isp[i]=1;
  for(int i=2; i<1024; ++i)
    if(isp[i])
      for(int j=i+i; j<1024; j+=i)
	isp[j]=0;
  vector<int> ret;
  for(int i=2; i<=n; ++i)
    if(isp[i])
      ret.push_back(i);
  return ret;
}

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> prs = er(n);
  int ok = 0;
  for(int i=0; i<prs.size(); ++i) {
    int t = prs[i];
    bool can = false;
    for(int j=0; j<prs.size()-1; ++j) {
      if(prs[j]+prs[j+1]+1==t) {
	can = true;
	break;
      }
    }
    if(can) ok++;
    if(ok >= k) break;
  }
  puts(ok >= k ? "YES" : "NO");
  return 0;
}