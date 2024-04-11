//I_l_M_P
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

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


#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 9;//NEED_CHANGE
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld PI = acos(-1);

const int N = 3.5e5 + 10;
const int block_sz = sqrt(3e5);
int pref[N], gblock[N], gbbegin[N];
bool bbegin[N];

_ int sum(int l, int r) {
    int res = (pref[r] - pref[l - 1]);
    if (res < 0) {
        res += MOD;
    }
    return res;
}

_ bool block_begin(int x) {
    return (x - 1) % block_sz == 0;
}

_ int get_block(int x) {
    return (x - 1) / block_sz;
}

_ int get_block_begin(int x) {
    return get_block(x) * block_sz + 1;
}

_ void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int fi[N], arr[N], s[N], kek[N], add_to_block[N], first_number[N], second_number[N];

_ void source() {
    int n, m;
    n = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
        bbegin[i] = block_begin(i);
        gblock[i] = get_block(i);
        gbbegin[i] = get_block_begin(i);
    }
    fi[1] = fi[2] = 1;
    pref[1] = 1;
    pref[2] = 2;
    for (int i = 3; i <= n; i++) {
        fi[i] = (fi[i - 1] + fi[i - 2]) % MOD;
        pref[i] = (pref[i - 1] + fi[i]) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        arr[i] = readInt();
        s[i] = (s[i - 1] + arr[i]) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        if (bbegin[i]) {
            kek[gblock[i]] = s[i + block_sz - 1] - s[i - 1];
            if (kek[gblock[i]] < 0) {
                kek[gblock[i]] += MOD;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int type, l, r;
        type = readInt();
        l = readInt();
        r = readInt();
        if (type == 1) {
            int start = l, block = gblock[l];
            while (l <= r && !bbegin[l]) {
                add(add_to_block[block], fi[l - start + 1]);
                add(arr[l], fi[l - start + 1]);
                l++;
            }
            block = gblock[l] - 1;
            while (l + block_sz - 1 <= r) {
                block++;
                add(add_to_block[block], sum(l - start + 1, l - start + block_sz));
                add(first_number[block], fi[l - start + 1]);
                add(second_number[block], fi[l - start + 2]);
                l += block_sz;
            }
            block = gblock[l];
            while (l <= r) {
                add(add_to_block[block], fi[l - start + 1]);
                add(arr[l], fi[l - start + 1]);
                l++;
            }
        }
        else {
            int ans = 0, block = gblock[l];
            if (!bbegin[l]) {
                int prev1 = first_number[block], prev2 = second_number[block];
                int from = gbbegin[l] + 2;
                for (int j = from; j <= l; j++) {
                    int to = prev1 + prev2;
                    if (to >= MOD) to -= MOD;
                    prev1 = prev2;
                    prev2 = to;
                }
                while (!bbegin[l] && l <= r) {
                    add(ans, prev2);
                    add(ans, arr[l]);
                    l++;
                    int to = prev1 + prev2;
                    if (to >= MOD) {
                        to -= MOD;
                    }
                    prev1 = prev2;
                    prev2 = to;
                }
            }
            block = gblock[l];
            while (l + block_sz - 1 <= r) {
                add(ans, kek[block]);
                add(ans, add_to_block[block]);
                block++;
                l += block_sz;
            }
            block = gblock[l];
            if (l <= r) {
                add(ans, arr[l]);
                add(ans, first_number[block]);
                l++;
                if (l <= r) {
                    add(ans, arr[l]);
                    add(ans, second_number[block]);
                    l++;
                    int prev1 = first_number[block], prev2 = second_number[block];
                    while (l <= r) {
                        int to = prev1 + prev2;
                        if (to >= MOD) {
                            to -= MOD;
                        }
                        prev1 = prev2;
                        prev2 = to;
                        add(ans, arr[l]);
                        add(ans, prev2);
                        l++;
                    }
                }
            }
            writeInt(ans);
            writeChar('\n');
        }
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}