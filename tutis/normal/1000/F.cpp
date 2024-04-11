/*input
6
1 1 2 3 2 4
2
2 6
1 2
*/
#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
typedef long double ld;
int kiek[709];
int kiekis[709 * 709];
bool yra[709][709];
void add(int i)
{
	kiekis[i]++;
	int a = i / 708;
	int b = i % 708;
	if (kiekis[i] == 1)
	{
		kiek[a]++;
		yra[a][b] = true;
	}
	else if (kiekis[i] == 2)
	{
		kiek[a]--;
		yra[a][b] = false;
	}
}
void rem(int i)
{
	kiekis[i]--;
	int a = i / 708;
	int b = i % 708;
	if (kiekis[i] == 0)
	{
		kiek[a]--;
		yra[a][b] = false;
	}
	else if (kiekis[i] == 1)
	{
		kiek[a]++;
		yra[a][b] = true;
	}
}
vector<int>skaiciai;
int atsakymas(int i)
{
	for (int t : skaiciai)
		if (yra[i][t])return i * 708 + t;
	return 0;
}
int get()
{
	for (int t : skaiciai)
		if (kiek[t])return atsakymas(t);
	return 0;
}
struct interv
{
	int l, r, v;
};
static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
	size_t remaining = stdinDataEnd - stdinPos;
	if (remaining < amount) {
		memmove(stdinBuffer, stdinPos, remaining);
		size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
		stdinPos = stdinBuffer;
		stdinDataEnd = stdinBuffer + remaining + sz;
		if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
			*stdinDataEnd = 0;
	}
}

int readIInt()
{
	readAhead(1000);

	int x = 0;

	while (*stdinPos >= '0' && *stdinPos <= '9') {
		x *= 10;
		x += *stdinPos - '0';
		++stdinPos;
	}
	stdinPos++;
	return x;
}

static const int buf_size = 4096;
interv queries[500005];
int ans[500005];
static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;
int main()
{
	srand(clock());
	for (int t = 0; t < 708; t++)
		skaiciai.push_back(t);
	random_shuffle(skaiciai.begin(), skaiciai.end());
	int n = readIInt();
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		a[i] = readIInt();
	int q = readIInt();
	for (int i = 0; i < q; i++)
	{
		queries[i].l = readIInt();
		queries[i].r = readIInt();
		queries[i].v = i;
	}
	int sz = 900 + rand() % 100;
	sort(queries, queries + q, [&](interv & a, interv & b) {
		if (a.l / sz != b.l / sz)
			return a.l < b.l;
		if ((a.l / sz) % 2 == 1)
			return a.r < b.r;
		else
			return a.r > b.r;
	});
	int l = 1;
	int r = 1;
	add(a[1]);
	for (int i = 0; i < q; i++)
	{
		while (r < queries[i].r)
		{
			r++;
			add(a[r]);
		}
		while (l > queries[i].l)
		{
			l--;
			add(a[l]);
		}
		while (r > queries[i].r)
		{
			rem(a[r]);
			r--;
		}
		while (l < queries[i].l)
		{
			rem(a[l]);
			l++;
		}
		ans[queries[i].v] = get();
	}
	for (int i = 0; i < q; i++)
	{
		writeInt(ans[i], '\n');
	}
}