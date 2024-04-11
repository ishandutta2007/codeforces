#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <set>

using namespace std;

const int MAXANS = 9;

vector< set<string> > count( string s ) {
	vector< set< string > > a(MAXANS + 1);
	for( int k = 1; k <= min( int(s.length()), MAXANS); ++k ) {
		set<string> x;
		for( int i = 0; i < s.length() - k + 1; ++i ) {
			x.insert( s.substr( i, k ) );
		}
		a[k] = x;
	}

	return a;
}

class Stringg {
public:
	string begin;
	string end;
	vector<set<string>> substr;

	Stringg( const string& s ) {
		begin = s.substr( 0, max( MAXANS, int( s.length() ) ) );
		end = s.substr( max( 0, int( s.length() - MAXANS ) ) );
		substr = count( s );
	}
	Stringg( const Stringg& a, const Stringg& b ) {
		begin = a.begin;
		if( begin.length() < MAXANS ) {
			int k = min( MAXANS -begin.length(), b.begin.length() );
			begin += b.begin.substr( 0, k );
		}
		if( b.end.length() >= MAXANS ) {
			end = b.end;
		} 
		else {
			int k = min( MAXANS -b.end.length(), a.end.length() );
			end = a.end.substr( a.end.length()-k ) + b.end;
		}
		
		substr = count( a.end+b.begin );
		for( int k = 1; k <= MAXANS; ++k ) {
			for( auto x : a.substr[k] ) {
				substr[k].insert( x );
			}
			for( auto x : b.substr[k] ) {
				substr[k].insert( x );
			}
		}
	}

	int getK() {
		long long l = 2;
		long long ans = 0;
		for( int k = 1; k <= MAXANS; ++k ) {
			if( substr[k].size() == l ) {
				ans = k;
			}
			l *= 2;
		}
		return ans;
	}
};



int main() {
	int n;
	cin >> n;

	vector< vector < set< string > > > a;
	vector< Stringg > b;
	for( int i = 0; i < n; ++i ) {
		string s;
		cin >> s;
		b.push_back( Stringg( s ) );
	}

	int m;
	cin >> m;
	
	for( int i = 0; i < m; ++i ) {
		int k, l;
		cin >> k >> l;
		b.push_back( Stringg( b[k-1], b[l-1] ) );
		cout << b[n + i].getK() << endl;
	}
	return 0;
}