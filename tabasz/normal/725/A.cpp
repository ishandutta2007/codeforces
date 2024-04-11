#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

string s;
int n, res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n >> s;
	int siz=s.size();
  for(int i=0; i<siz; i++)
  {
    if(s[i]=='<')
      res++;
     else
      break;
  }
  for(int i=siz-1; i>=0; i--)
  {
    if(s[i]=='>')
      res++;
     else
      break;
  }
  cout<< res << '\n';
	return 0;
}