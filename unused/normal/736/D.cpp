#include "bits/stdc++.h"
using namespace std;

#ifdef ONLINE_JUDGE
#define SIZE 2000
#else
#define SIZE 5
#endif

pair<int, int> dat[500005];
bitset<SIZE> org[2000];
bitset<SIZE> mat[2000];
bitset<SIZE> marked[2000];
bitset<SIZE> row[2000];
bitset<SIZE> rowmark[2000];
bool ans[2000][2000];

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
		while ((c < '0' || c > '9') && c != '-') {
			c = readChar();
		}
		int ret = 0; bool neg = c == '-';
		if (neg) c = readChar();
		while (c >= '0' && c <= '9') {
			ret = ret * 10 + c - '0';
			c = readChar();
		}
		return neg ? -ret : ret;
	}
	char outbuf[BSIZE + 20];
	char* outp = outbuf;

	void printYes()
	{
		char *end = outp;
		*end++ = 'Y';
		*end++ = 'E';
		*end++ = 'S';
		*end++ = '\n';
		if (end < outbuf + BSIZE) outp = end;
		else
		{
			fwrite(outbuf, end - outbuf, 1, stdout);
			outp = outbuf;
		}
	}

	void printNo()
	{
		char *end = outp;
		*end++ = 'N';
		*end++ = 'O';
		*end++ = '\n';
		if (end < outbuf + BSIZE) outp = end;
		else
		{
			fwrite(outbuf, end - outbuf, 1, stdout);
			outp = outbuf;
		}
	}

	void flush()
	{
		fwrite(outbuf, outp - outbuf, 1, stdout);
	}
}

int main()
{
	int n = fio::readInt(), m = fio::readInt();
	for (int i = 0; i < m; i++)
	{
		dat[i].first = fio::readInt();
		dat[i].second = fio::readInt();
		--dat[i].first; --dat[i].second;
		org[dat[i].first][dat[i].second] = true;
	}

	for (int i = 0; i < n; i++) mat[i] = org[i];

	for (int i = 0; i < n; i++) marked[i][i] = true;

	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < n - i; j++)
		{
			if (mat[j][i]) break;
		}

		row[i] = mat[j];
		rowmark[i] = marked[j];

		for (int k = 0; k < n - i; k++)
		{
			if (j == k) continue;
			if (mat[k][i])
			{
				mat[k] ^= mat[j];
				marked[k] ^= marked[j];
			}
		}

		swap(mat[j], mat[n - i - 1]);
		swap(marked[j], marked[n - i - 1]);
	}

	for (int i = 0; i < n; i++)
	{
		bitset<SIZE> now = row[i];
		bitset<SIZE> mark = rowmark[i];
		for (int j = i + 1; j < n; j++)
		{
			if (now[j])
			{
				now ^= row[j];
				mark ^= rowmark[j];
			}
		}

		for (int j = 0; j < n; j++)
		{
			if (mark[j] && org[j][i]) ans[j][i] = true;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (ans[dat[i].first][dat[i].second]) fio::printNo();
		else fio::printYes();
	}
	fio::flush();
	_Exit(0);
}