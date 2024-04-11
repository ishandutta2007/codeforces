#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>

string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> s;
	int x=0, xx=0;
	vector<int> V;
	for(int i=0; i<(int)s.size(); i++)
	{
		if(s[i]=='(') {x++; xx++;}
		if(s[i]==')') {x--; xx--;}
		if(s[i]=='#')
		{
			xx=0;
			x--;
			V.PB(1);
		}
		if(x<0)
		{
			cout<< "-1\n";
			return 0;
		}
	}
	V[V.size()-1]+=x;
	x=0;
	int tmp=0;
	for(int i=0; i<(int)s.size(); i++)
	{
		if(s[i]=='(') x++;
		if(s[i]==')') x--;
		if(s[i]=='#')
		{
			x-=V[tmp];
			tmp++;
		}
		if(x<0)
		{
			cout<< "-1\n";
			return 0;
		}
 	}
	for(int i=0; i<(int)V.size(); i++) cout<< V[i] << '\n';
	return 0;
}