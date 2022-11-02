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

string s, s2;
LL res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> s;
	int siz=s.size();
	LL x=0;
	for(int i=0; i<siz-1; i++)
	{
	  x*=10;
	  x+=(int)s[i]-(int)'0';
	}
	res+=((x-1)/4)*16;
	if(x%2==0)
	  res+=7;
	if(s[siz-1]=='f')
	  res+=1;
	if(s[siz-1]=='e')
	  res+=2;
	if(s[siz-1]=='d')
	  res+=3;
	if(s[siz-1]=='a')
	  res+=4;
	if(s[siz-1]=='b')
	  res+=5;
	if(s[siz-1]=='c')
	  res+=6;
	cout<< res << '\n';
	return 0;
}