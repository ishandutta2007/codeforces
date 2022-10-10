#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto query = [&](int x, int y)->int{
		cout << "? " << x << " " << y << endl;
		int dist;
		cin >> dist;
		if(!~dist) exit(0);
		return dist;
	};
	auto answer = [&](array<int, 2> p, array<int, 2> q)->void{
		cout << "! " << p[0] << " " << p[1] << " " << q[0] << " " << q[1] << endl;
		exit(0);
	};
	#ifdef LOCAL
	const int mx = 30;
	#else
	const int mx = 1e9;
	#endif
	array<int, 4> d{
		2 + query(1, 1),
		mx - 1 - query(mx, 1),
		2 * mx - query(mx, mx),
		1 - mx + query(1, mx)
	};
	array<int, 2> p{
		1 + query(1, d[0] - d[3] >> 1),
		1 + query(d[1] + d[0] >> 1, 1)
	};
	array<int, 2> q{
		mx - query(mx, d[2] - d[1] >> 1),
		mx - query(d[3] + d[2] >> 1, mx)
	};
	answer(p, q);
	return 0;
}

/*
10, 20
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////