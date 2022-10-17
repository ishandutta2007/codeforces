#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 101010;
int n, m, seed, vmax;
int a[MAXN];
int rnd()
{
	int ret = seed;
	seed = ((long long)seed * 7 + 13) % 1000000007;
	return ret;
}
/*class Node
{
public:
	int st, ed, vst, ved, v;
	Node *l, *r;
	Node(){}
	Node(int st, int ed, int pos, int v, Node *l, Node *r): vst(pos), ved(pos), v(v), l(l), r(r) {}
}*root;
Node *build(int st, int ed)
{
	if(st == ed)
		return new Node(st, a[st], 0, 0);
	int mi = (st + ed) / 2;
	return new Node(mi, a[mi], mi == st ? 0 : build(st, mi - 1), build(mi + 1, ed));
}*/
int MOD;
long long quickmul(long long a1, int b)
{
	int a = a1 % MOD;
	long long ret = 1;
	for(; b; b >>= 1, a = (long long)a * a % MOD)
		if(b & 1)
			ret = ret * a % MOD;
//	if(ret < 0)
//		exit(1);
	return ret;
}
vector<pair<int, long long> > b;//end, value
vector<pair<long long, int> > buf;
int main()
{
	scanf("%d%d%d%d", &n, &m, &seed, &vmax);
	for(int i = 1; i <= n; i++)
		a[i] = rnd() % vmax + 1;
	b.resize(n + 1);
	for(int i = 1; i <= n; i++)
		b[i] = make_pair(i, a[i]);
	b[0] = make_pair(0, 0);
//	root = build(1, n);
	for(int i = 1; i <= m; i++)
	{
		int op, l, r, x, y;
		op = rnd() % 4 + 1;
		l = rnd() % n + 1;
		r = rnd() % n + 1;
		if(l > r)
			swap(l, r);
		if(op == 3)
			x = rnd() % (r - l + 1) + 1;
		else
			x = rnd() % vmax + 1;
		if(op == 4)
			y = rnd() % vmax + 1;
		MOD = y;
//		printf("%d %d %d %d %d\n", op, l, r, x, y);
//		for(int j = 0; j < (int)b.size(); j++)
//			if(b[j].second < 0)
//				return 1;
//			printf("%d ; %I64d\n", b[j].first, b[j].second);
		
		if(op == 1)
		{
			bool flag1 = false;
			for(int j = 0; j < (int)b.size(); j++)
				if(b[j].first == l - 1)
					flag1 = true;
				else if(!flag1 && b[j].first >= l)
				{
					if(b[j].first >= r)
					{
						pair<int, long long> tmp = b[j];
						b.erase(b.begin() + j);
						b.insert(b.begin() + j, make_pair(l - 1, tmp.second));
						b.insert(b.begin() + j + 1, make_pair(r, tmp.second + x));
						b.insert(b.begin() + j + 2, tmp);
						break;
					}
					b.insert(b.begin() + j, make_pair(l - 1, b[j].second));
					flag1 = true;
				}
				else if(flag1)
				{
					if(b[j].first == r)
					{
						b[j].second += x;
						break;
					}
					else if(b[j].first > r)
					{
						b.insert(b.begin() + j, make_pair(r, b[j].second));
						b[j].second += x;
						break;
					}
					else
						b[j].second += x;
				}
		}
		else if(op == 2)
		{
			int flag1 = 0;
			for(int j = 0; j < (int)b.size(); j++)
				if(b[j].first == l - 1)
					flag1 = j + 1;
				else if(!flag1 && b[j].first >= l)
				{
					if(b[j].first >= r)
					{
						pair<int, long long> tmp = b[j];
						b.erase(b.begin() + j);
						b.insert(b.begin() + j, make_pair(l - 1, tmp.second));
						b.insert(b.begin() + j + 1, make_pair(r, x));
						b.insert(b.begin() + j + 2, tmp);
						break;
					}
					b.insert(b.begin() + j, make_pair(l - 1, b[j].second));
					flag1 = j + 1;
				}
				else if(flag1)
				{
					if(b[j].first == r)
					{
						b.erase(b.begin() + flag1, b.begin() + j + 1);
						b.insert(b.begin() + flag1, make_pair(r, x));
						break;
					}
					else if(b[j].first > r)
					{
						int tmp = b[j].first;
						long long tmp2 = b[j].second;
						b.erase(b.begin() + flag1, b.begin() + j + 1);
						b.insert(b.begin() + flag1, make_pair(r, x));
						b.insert(b.begin() + flag1 + 1, make_pair(tmp, tmp2));
						break;
					}
				}
		}
		else if(op == 3)
		{
			buf.clear();
			bool flag1 = false;
			for(int j = 0; j < (int)b.size(); j++)
				if(b[j].first == l - 1)
					flag1 = true;
				else if(!flag1 && b[j].first >= l)
				{
					if(b[j].first >= r)
					{
						buf.push_back(make_pair(b[j].second, r - l + 1));
						break;
					}
					buf.push_back(make_pair(b[j].second, b[j].first - l + 1));
					flag1 = true;
				}
				else if(flag1)
				{
					if(b[j].first >= r)
					{
						buf.push_back(make_pair(b[j].second, r - b[j - 1].first));
						break;
					}
					else
						buf.push_back(make_pair(b[j].second, b[j].first - b[j - 1].first));
				}
			sort(buf.begin(), buf.end());
			int tmp = 0;
			for(int i = 0; i < (int)buf.size(); i++)
				if((tmp += buf[i].second) >= x)
				{
					printf("%I64d\n", buf[i].first);
					break;
				}
		}
		else if(op == 4)
		{
			int ans = 0;
			bool flag1 = false;
			for(int j = 0; j < (int)b.size(); j++)
				if(b[j].first == l - 1)
					flag1 = true;
				else if(!flag1 && b[j].first >= l)
				{
					if(b[j].first >= r)
					{
						ans = quickmul(b[j].second, x) * (r - l + 1) % y;
						break;
					}
					ans = (ans + quickmul(b[j].second, x) * (b[j].first - l + 1)) % y;
					flag1 = true;
				}
				else if(flag1)
				{
					if(b[j].first >= r)
					{
						ans = (ans + quickmul(b[j].second, x) * (r - b[j - 1].first)) % y;
//						if(ans < 0)
//						{
//							printf("%I64d %d %d %d\n", quickmul(b[j].second, x), r, b[j - 1].first, b[j].first);
//							exit(1);
//						}
						break;
					}
					else
						ans = (ans + quickmul(b[j].second, x) * (b[j].first - b[j - 1].first)) % y;
				}
			printf("%d\n", ans);
		}
	}
	return 0;
}