#include <bits/stdc++.h>
using namespace std;

struct seqType
{
	int num;
	int cc;
}temp;

struct crossType
{
	crossType() { linc = ldec = rinc = rdec = 0; }

	int linc, ldec, rinc, rdec;
};

vector < seqType > seq;
vector < crossType > cross;
int k;

int maxlen ( int l, int r );

int main()
{
	ios::sync_with_stdio ( false );

	int n, t;
	cin >> n;

	temp.cc = 1;
	k = -1;
	for ( int i = 0; i < n; i++ ){
		cin >> t;
		if ( seq.empty() || ( t != seq[k].num ) ){
			temp.num = t;
			seq.push_back ( temp );
			k++;
		}else{
			seq[k].cc++;
		}
	}
	k++;

	cross.resize ( k );
	cross[0].linc = cross[0].ldec = 0;
	for ( int i = 1; i < k; i++ ){
		if ( seq[i].num - seq[i-1].num == 1 ){
			cross[i].linc = cross[i-1].ldec + seq[i-1].cc;
		}else if ( seq[i-1].num - seq[i].num == 1 ){
			cross[i].ldec = cross[i-1].linc + seq[i-1].cc;
		}
	}
	cross[k-1].rinc = cross[k-1].rdec = 0;
	for ( int i = k-2; i >= 0; i-- ){
		if ( seq[i].num - seq[i+1].num == 1 ){
			cross[i].rinc = cross[i+1].rdec + seq[i+1].cc;
		}else if ( seq[i+1].num - seq[i].num == 1 ){
			cross[i].rdec = cross[i+1].rinc + seq[i+1].cc;
		}
	}

	cout << maxlen ( 0, k );
}

int maxlen ( int l, int r )
{
	if ( r - l == 1 ) return seq[l].cc;

	int mid = ( l + r ) / 2, maxi;
	
	maxi =  max ( maxlen ( l, mid ), maxlen ( mid, r ) );

	if ( seq[mid].num - seq[mid-1].num == 1 ){
		maxi = max ( maxi, ( cross[mid].rinc + seq[mid].cc + seq[mid-1].cc + cross[mid-1].ldec ) );
	}else if ( seq[mid-1].num - seq[mid].num == 1 ){
		maxi = max ( maxi, ( cross[mid].rdec + seq[mid].cc + seq[mid-1].cc + cross[mid-1].linc ) );
	}

	return maxi;
}