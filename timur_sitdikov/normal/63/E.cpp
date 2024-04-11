#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

vector<int> good_masks;
char col[1<<19];

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	int i, j;
	for(i = 0; i <= 18; i++)
		good_masks.pb(1<<i);
	//19
	for(i = 0; i <= 17; i++)
		if (i!=2 && i!= 6 && i!=11 && i!=15)
			good_masks.pb((1<<i)|(1<<(i+1)));
	//33
	for(i = 0; i <= 16; i++)
		if (i!=1 && i!=2 && i!= 5 && i!= 6 && i!=10 && i!=11 && i!=14 && i!=15)
			good_masks.pb((1<<i)|(1<<(i+1))|(1<<(i+2)));
	//42
	good_masks.pb((1<<3)|(1<<(4))|(1<<(5))|(1<<(6)));
	good_masks.pb((1<<7)|(1<<(8))|(1<<(9))|(1<<(10)));
	good_masks.pb((1<<7)|(1<<(8))|(1<<(9))|(1<<(10))|(1<<(11)));
	good_masks.pb((1<<(8))|(1<<(9))|(1<<(10))|(1<<(11)));
	good_masks.pb((1<<12)|(1<<(13))|(1<<(14))|(1<<(15)));
	//47
	for(i=0; i<=2; i++)
	{
		good_masks.pb((1<<i)|(1<<(i+4)));
		good_masks.pb((1<<i)|(1<<(i+3)));
		good_masks.pb((1<<i)|(1<<(i+4))|(1<<(i+9)));
		good_masks.pb((1<<i)|(1<<(i+3))|(1<<(i+7)));
	}
	//59
	for(i=16; i<=18; i++)
	{
		good_masks.pb((1<<i)|(1<<(i-4)));
		good_masks.pb((1<<i)|(1<<(i-3)));
		good_masks.pb((1<<i)|(1<<(i-4))|(1<<(i-9)));
		good_masks.pb((1<<i)|(1<<(i-3))|(1<<(i-7)));
	}
	//71
	for(i=8; i<=10; i++)
	{
		good_masks.pb((1<<i)|(1<<(i-4)));
		good_masks.pb((1<<i)|(1<<(i+4)));
		good_masks.pb((1<<i)|(1<<(i-5)));
		good_masks.pb((1<<i)|(1<<(i+5)));
		good_masks.pb((1<<i)|(1<<(i-4))|(1<<(i+4)));
		good_masks.pb((1<<i)|(1<<(i-5))|(1<<(i+5)));
	}
	//89
	good_masks.pb((1<<7)|(1<<3));
	good_masks.pb((1<<7)|(1<<12));
	good_masks.pb((1<<11)|(1<<6));
	good_masks.pb((1<<11)|(1<<15));
	//93
	good_masks.pb((1<<1)|(1<<(5))|(1<<(10))|(1<<(15)));
	good_masks.pb((1<<0)|(1<<(4))|(1<<(9))|(1<<(14)));
	good_masks.pb((1<<0)|(1<<(4))|(1<<(9))|(1<<(14))|(1<<(18)));
	good_masks.pb((1<<(4))|(1<<(9))|(1<<(14))|(1<<(18)));
	good_masks.pb((1<<3)|(1<<8)|(1<<13)|(1<<17));
	//98
	good_masks.pb((1<<1)|(1<<(4))|(1<<(8))|(1<<(12)));
	good_masks.pb((1<<2)|(1<<(5))|(1<<(9))|(1<<(13)));
	good_masks.pb((1<<2)|(1<<(5))|(1<<(9))|(1<<(13))|(1<<(16)));
	good_masks.pb((1<<(5))|(1<<(9))|(1<<(13))|(1<<(16)));
	good_masks.pb((1<<6)|(1<<10)|(1<<14)|(1<<17));
	//103
	for(i = 0; i < (1<<19); i++)
	{
		if (!col[i])
		{
			for(j = 0; j<(int)good_masks.size(); j++)
				if (!(i&good_masks[j]))
					col[i|good_masks[j]] = 1;
		}
	}
	int mask = 0;
	string s;
	for(i = 0; i < 19; i++)
	{
		cin >> s;
		if (s[0]=='O')
			mask^=(1<<i);
	}
	if (col[mask])
		printf("Karlsson");
	else printf("Lillebror");
}