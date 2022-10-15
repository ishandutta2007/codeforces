#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cassert>
#include <vector>
#define all(x) x.begin() , x.end()
#define fi first
#define se second
#define pb push_back
#define umax( x , y ) x = max( x , (y) )
#define umin( x , y ) x = min( x , (y) )
#define For( i , a ) for(int i=1;i<=a;i++)
#define ort (b+s)/2
#define y2 asrwjaelkf
#define y1 asseopirwjaelkf
#define set multiset

using namespace std;

typedef long long Lint;
typedef double db;
typedef pair<int,int> ii;
typedef pair<Lint,int> li;
typedef pair<int,char> ic;
typedef pair<db,db> dd;
typedef pair<ii,int> iii;
typedef pair<ii,ii> i4;

const int maxn = 1000020;
const int maxm = 1000020;
const int MOd = 998244353;

int a, b;
vector< vector<char> > ar;
vector< vector<char> > bs, H;
int ans = 1e9;

int f( vector< vector<char> > &v ) {
	int ret = 0;
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			ret += v[i][j] != ar[i][j];
	return ret;
}

char get( int i, char x, char y ) {
	if( i&1 ) return y;
	return x;
}

void ver( char x1, char y1, char x2, char y2 ) {
	int tot = 0;
	for(int i=0;i<a;i++) {
		int c1 = 0, c2 = 0;

		char x = x1, y = y1;
		if( i&1 ) x = x2, y = y2;

		for(int j=0;j<b;j++) {
			c1 += get( j, x, y ) != ar[i][j];
			c2 += get( j, y, x ) != ar[i][j];
		}
		if( c1 < c2 ) for(int j=0;j<b;j++) bs[i][j] = get( j, x, y );
		else		  for(int j=0;j<b;j++) bs[i][j] = get( j, y, x );
	}
	int t = f( bs );
	if( t < ans ) ans = t, H = bs;
}

void hor( char x1, char y1, char x2, char y2 ) {
	ver( x1, y1, x2, y2 );
	int tot = 0;
	for(int i=0;i<b;i++) {
		int c1 = 0, c2 = 0;
		char x = x1, y = y1;
		if( i&1 ) x = x2, y = y2;
		for(int j=0;j<a;j++) {
			c1 += get( j, x, y ) != ar[j][i];
			c2 += get( j, y, x ) != ar[j][i];
		}
		if( c1 < c2 ) for(int j=0;j<a;j++) bs[j][i] = get( j, x, y );
		else		  for(int j=0;j<a;j++) bs[j][i] = get( j, y, x );
	}
	int t = f( bs );
	if( t <= ans ) ans = t, H = bs;
}

void solve() {

	scanf("%d %d",&a,&b);

	ar.resize( a );
	for(int i=0;i<a;i++) ar[i].resize(b);

	bs.resize( a );
	for(int i=0;i<a;i++) bs[i].resize(b);


	H.resize( a );
	for(int i=0;i<a;i++) H[i].resize(b);

	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			scanf(" %c",&ar[i][j]);


	//for(int i=0;i<a;i++)
	//	for(int j=0;j<b;j++)
	//		scanf(" %c",&bs[i][j]);

	//printf("---- %d\n",f(bs));
	
	hor( 'A', 'G', 'T', 'C' );
	hor( 'A', 'T', 'G', 'C' );
	hor( 'A', 'C', 'G', 'T' );
	hor( 'G', 'T', 'A', 'C' );
	hor( 'G', 'C', 'A', 'T' );
	hor( 'T', 'C', 'A', 'G' );

	//printf("%d\n",ans);
	for(int i=0;i<a;i++,printf("\n"))
		for(int j=0;j<b;j++)
			printf("%c",H[i][j]);
}

int main() {

    //freopen("asd.in","r",stdin);
    //freopen("output17.txt","w",stdout);
	int n = 1;

	while( n-- ) solve();

	return 0;
}