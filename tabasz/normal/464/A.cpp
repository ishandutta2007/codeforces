#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back

int n, p;
string s;

bool check(char c, int ind)
{
	if(ind-2>=0 && s[ind-2]==c) return false;
	if(ind-1>=0 && s[ind-1]==c) return false;
	return true;
}

void lol(int ind)
{
	int x=0;
	while((ind-2>=0 && s[ind-2]==(char)(x+(int)'a')) || (ind-1>=0 && s[ind-1]==(char)(x+(int)'a'))) x++;
	s[ind]=(char)(x+(int)'a');
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n >> p >> s;
	if(p==1 || (p==2 && n>2))
	{
		cout<< "NO\n";
		return 0;
	}
	if(p==2)
	{
		if(n==1)
		{
			if(s[0]=='a') cout<< "b\n";
			else cout<< "NO\n";
		}
		else
		{
			if(s[0]=='a') cout<< "ba\n";
			else cout<< "NO\n";
		}
		return 0;
	}
	for(int i=(int)s.size()-1; i>=0; i--)
	{
		for(int j=(int)s[i]-(int)'a'+1; j<p; j++)
		{
			char c=(char)(j+(int)'a');
			if(check(c, i))
			{
				s[i]=c;
				for(int k=i+1; k<(int)s.size(); k++) lol(k);
				cout<< s << '\n';
				return 0;
			}
		}
	}
	cout<< "NO\n";
	return 0;
}