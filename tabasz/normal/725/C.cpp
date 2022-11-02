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
char r[2][27];
vector<int> A[27];

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> s;
	for(int i=0; i<27; i++)
	  A[(int)s[i]-(int)'A'].PB(i);
	for(int i=0; i<26; i++)
	{
	  if(A[i].size()<2)
	    continue;
	  if(A[i][1]==A[i][0]+1)
	  {
	    cout<< "Impossible\n";
	    return 0;
	  }
	  int l=A[i][1]-A[i][0]-1, ind=12-l/2, ind2=12-l/2;
	  r[1][ind]=(char)((int)'A'+i);
	  int tmp=A[i][0]+1;
	//  printf("%d %d %d\n", l, ind, tmp);
	  ind++;
	  while(tmp!=A[i][1] && ind<=12)
	  {
	    r[1][ind]=s[tmp];
	    tmp++;
	    ind++;
	  }
	  ind=12;
	  while(tmp!=A[i][1])
	  {
	    r[0][ind]=s[tmp];
	    tmp++;
	    ind--;
	  }
	  tmp++;
	  while(tmp<27 && ind>=0)
	  {
	    r[0][ind]=s[tmp];
	    tmp++;
	    ind--;
	  }
	  ind=0;
	  while(tmp<27)
	  {
	    r[1][ind]=s[tmp];
	    tmp++;
	    ind++;
	  }
	  tmp=A[i][0]-1;
	  ind=ind2-1;
	  while(tmp>=0 && ind>=0)
	  {
	    r[1][ind]=s[tmp];
	    tmp--;
	    ind--;
	  }
	  ind=0;
	  while(tmp>=0)
	  {
	    r[0][ind]=s[tmp];
	    tmp--;
	    ind++;
	  }
	}
	for(int i=0; i<2; i++)
	{
	  for(int j=0; j<13; j++)
	    cout<< r[i][j];
	  cout<< '\n';
	}
	return 0;
}