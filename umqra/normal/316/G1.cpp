#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define mp make_pair
#define X first
#define Y second

const int N = (int)1e4;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;
const int p1 = 1231723;
const int p2 = 92345;

pii HashStr[N];
pii deg[N];
pii HashT[10][N];
string str;
string task[10];
int l[10], r[10];
int dp[N][10];
char zStr[N];
int z[N];
int good[N];
int lenEdge[N];

set <pii> allStr;
int code(char c)
{
	return c - 'a' + 1;
}

int add(int a, int b)
{               
	if (a + b < mod)
		return a + b;
	else if (a + b >= mod)
		return a + b - mod;
	return a + b + mod;
}

int mult(int a, int b)
{
	ll c = (ll)a * (ll)b;
	return (int)(c % (ll)mod);
}

pii neg(pii a)
{
	return mp(mod - a.X, mod - a.Y);
}

pii add(pii a, pii b)
{
	return mp(add(a.X, b.X), add(a.Y, b.Y));
}

pii mult(pii a, pii b)
{
	return mp(mult(a.X, b.X), mult(a.Y, b.Y));
}

void calcDeg()
{
	deg[0] = mp(1, 1);
	for (int i = 1; i < N; i++)
		deg[i] = mult(deg[i - 1], mp(p1, p2));
}

void calcHashStr()
{
	HashStr[0] = mp(code(str[0]), code(str[0]));
	for (int i = 1; i < (int)str.length(); i++)
		HashStr[i] = add(HashStr[i - 1], mult(deg[i], mp(code(str[i]), code(str[i]))));   
}

void calcHash(string cS, int ind)
{
	HashT[ind][0] = mp(code(cS[0]), code(cS[0]));
	for (int i = 1; i < (int)cS.length(); i++)
		HashT[ind][i] = add(HashT[ind][i - 1], mult(deg[i], mp(code(cS[i]), code(cS[i]))));
}

pii getHashStr(int a, int b)
{
	pii res = add(HashStr[b], (a == 0 ? mp(0, 0) : neg(HashStr[a - 1])));
	res = mult(res, deg[N - a - 1]);
	return res;
}

pii getHashT(int ind)
{
	pii res = HashT[ind][(int)task[ind].length() - 1];
	res = mult(res, deg[N - 1]);
	return res;
}

void calcZ(int len)
{
	z[0] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < len; i++)
	{
		z[i] = 0;
		if (i <= r)
			z[i] = min(z[i - l], r - i + 1);
		while (z[i] + i < len && zStr[i + z[i]] == zStr[z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
		{
			r = i + z[i] - 1;
			l = i;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	calcDeg();
	cin >> str;
	calcHashStr();
	int n;
	scanf("%d", &n);	
	for (int i = 0; i < n; i++)
	{
		cin >> task[i];
		cin >> l[i] >> r[i];
	}

	for (int i = 0; i < (int)str.length(); i++)
	{                                  
		for (int s = 0; s < (int)str.length(); s++)
			good[s] = 0;
		for (int s = 0; s < (int)str.length() - i; s++)
			zStr[s] = str[i + s];
		zStr[(int)str.length() - i] = '#';
		for (int k = 0; k < n; k++)
		{
			for (int q = 0; q < (int)task[k].length(); q++)
				zStr[(int)str.length() - i + 1 + q] = task[k][q];
			calcZ((int)str.length() - i + (int)task[k].length() + 1);
			int ind = 0;
			for (int s = (int)str.length() - i + 1; s < (int)str.length() - i + (int)task[k].length() + 1; s++)
				lenEdge[ind++] = z[s];    
			sort(lenEdge, lenEdge + ind);
			int ptr = 0;
			for (int len = 1; len <= (int)str.length() - i; len++)
			{
				while (ptr < ind && lenEdge[ptr] < len)
					ptr++;
				if (ind - ptr >= l[k] && ind - ptr <= r[k])
					good[len]++;
			}
		}                                       
		for (int len = 1; len <= (int)str.length() - i; len++)
		{
			//cout << len << ":" << good[len] << endl;  
			if (good[len] == n)
			{                                    
				pii curHash = getHashStr(i, i + len - 1);

				if (allStr.find(curHash) == allStr.end())
				{
					allStr.insert(curHash);                          
                }
			}
		}

	}

	cout << allStr.size();

	return 0;
}