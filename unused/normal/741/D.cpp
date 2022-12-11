#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

int val[500005];
int num[500005];
int ans[500005];
int depth[500005];
vector<int> graph[500005];
int n;

namespace fio {
	const int BSIZE = 524288;
	char buffer[BSIZE];
	int p = BSIZE;
	inline char readChar() {
		if (p == BSIZE) {
			fread(buffer, 1, BSIZE, stdin);
			p = 0;
		}
		return buffer[p++];
	}
	int readInt() {
		char c = readChar();
		while (c < '0') {
			c = readChar();
		}
		int ret = 0;
		while (c >= '0') {
			ret = ret * 10 + c - '0';
			c = readChar();
		}
		return ret;
	}
	char nextChar()
	{
		char c = readChar();
		while (c < 'a' && c > 'z') c = readChar();
		return c;
	}
	char outbuf[BSIZE + 20];
	char* outp = outbuf;

	void printInt(int n)
	{
		if (n < 0) n = -n, *outp++ = '-';
		char *end = outp;
		do
		{
			*end++ = n % 10 + '0';
			n /= 10;
		} while (n);
		reverse(outp, end);
		*end++ = ' ';
		if (end < outbuf + BSIZE) outp = end;
		else
		{
			fwrite(outbuf, 1, end - outbuf, stdout);
			outp = outbuf;
		}
	}

	void flush()
	{
		fwrite(outbuf, 1, outp - outbuf, stdout);
	}
}

unordered_map<int, int> dfs(int t)
{
    int aaa = 0;

	if (graph[t].empty())
	{
		unordered_map<int, int> ret;
		ret.emplace(num[t], depth[t]);
		return ret;
	}

	vector<unordered_map<int, int>> maps;
	for (int nxt : graph[t])
	{
		num[nxt] = val[nxt] ^ num[t];
		depth[nxt] = depth[t] + 1;
		maps.emplace_back(dfs(nxt));
		if (aaa < ans[nxt]) aaa = ans[nxt];
	}

	int maxidx = 0;
	for (int i = 1; i < maps.size(); i++)
	{
		if (maps[maxidx].size() < maps[i].size()) maxidx = i;
	}

	if (maxidx != 0) swap(maps[0], maps[maxidx]);

	unordered_map<int, int> ret = move(maps[0]);

	for (int i = 1; i < maps.size(); i++)
	{
		for (auto &&e : maps[i])
		{
			for (int j = -1; j < 22; j++)
			{
				auto itr = ret.find(e.first ^ (j == -1 ? 0 : (1 << j)));
				if (itr == ret.end()) continue;

				if (aaa < itr->second + e.second - 2 * depth[t])
				    aaa = itr->second + e.second - 2 * depth[t];
			}
		}

		for (auto &&e : maps[i])
		{
			auto itr = ret.insert(e);
			if (itr.second == false)
			{
                auto &z = itr.first->second;
                if (z < e.second) z = e.second;
			}
		}
	}

	ret.emplace(num[t], depth[t]);

	for (int i = -1; i < 22; i++)
	{
		auto itr = ret.find(num[t] ^ (i == -1 ? 0 : (1 << i)));
		if (itr != ret.end())
		{
			if (aaa < itr->second - depth[t]) aaa = itr->second - depth[t];
		}
	}

    ans[t] = aaa;

	return ret;
}

int main()
{
	n = fio::readInt();
	for (int i = 1; i < n; i++)
	{
		int a; char ch;
		a = fio::readInt();
		ch = fio::readChar();
		val[i] = 1 << (ch - 'a');
		a--;
		graph[a].push_back(i);
	}

	dfs(0);

	for (int i = 0; i < n; i++) fio::printInt(ans[i]);
	fio::flush();
	fflush(stdout);
//    auto bbb = chrono::high_resolution_clock::now() - aaa;
//    printf("\n%lld\n", chrono::duration_cast<chrono::milliseconds>(bbb).count());
	_Exit(0);
}