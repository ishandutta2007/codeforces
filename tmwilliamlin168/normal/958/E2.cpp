#include <bits/stdc++.h>
using namespace std;

#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

inline int in() {
	int result = 0;
	char ch = getchar_unlocked();
	while (true) {
		if(ch >= '0' && ch <= '9')
			break;
		ch = getchar_unlocked();
	}
	result = ch-'0';
	while(true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9')
			break;
		result = result*10 + (ch - '0');
	}
	return result;
}
inline void out(int x) {
	int rev=x, count = 0;
	if(x == 0) {
putchar_unlocked('0');
putchar_unlocked('\n');
return;
}
	while((rev % 10) == 0) {
++count;
rev /= 10;
} //obtain the count of the number of 0s
	rev = 0;
	while(x != 0) {
rev = rev*10 + x % 10;
x /= 10;
} //store reverse of N in rev
	while(rev != 0) {
putchar_unlocked(rev % 10 + '0');
rev /= 10;
}
	while(count--)
putchar_unlocked('0');
	putchar_unlocked('\n');
}

const int mxN = 500001;
int N, K, sol, value, kk, l, r, pos, C[mxN], D[mxN], nxt[mxN], last[mxN];
struct _comp {
    bool operator () ( const int &i, const int &j ) {
        return C[i] != C[j] ? C[i] < C[j] : i < j;
    }
};
set< int, _comp > S;

int main() {
    K=in(), N=in();
    S.clear();
    REP(i, N) {
    	D[i]=in();
    }
	sort(D, D+N);
    REP( i, N ) {
        if ( i ) {
            C[i] = D[i]-D[i-1];
            S.insert( i );
            nxt[i] = i + 1;
            last[i] = i - 1;
        }
    }
    nxt[N - 1] = last[1] = 0;
    sol=0;
    REP( i, K ) {
        pos = *S.begin();
        l = last[pos];
        r = nxt[pos];
        S.erase( pos );
        if ( l ) S.erase( l );
        if ( r ) S.erase( r );
        sol += C[pos];
        C[pos] = C[l] + C[r] - C[pos];
        if ( l && r ) {
            S.insert( pos );
            last[pos] = last[l];
            nxt[pos] = nxt[r];
        } else
            pos = 0;
        if ( last[l] ) nxt[ last[l] ] = pos;
        if ( nxt[r] ) last[ nxt[r] ] = pos;
    }
    out(sol);
}