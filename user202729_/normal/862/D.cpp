#include <iostream>
#include <string>
#include <vector>

struct result {
	int left, right, dist;
};

//void ask(result& r) {
//	std::cout << "? " << r.query >> '\n';
//	std::cin >> r.dist;
//}


int main() {
	int n;
	std::cin >> n;
	std::string query;
	int n1;
	query = "? ";
	for (int i = 0; i < n; ++i) query += '1';
	query += '\n';
	std::cout << query;
	std::cin >> n1;
	int pos0 = -1, pos1 = -1, ql = 0, qr = n;
	while (pos0 == -1 || pos1 == -1) {
		query = "? ";
		int mid = (ql + qr + 1) / 2;
		for (int i = 0  ; i < ql ; ++i) query += '1';
		for (int i = ql ; i < mid; ++i) query += '0';
		for (int i = mid; i < n  ; ++i) query += '1';
		query += '\n';
		std::cout << query;
		int dist1;
		std::cin >> dist1;

		int n1to0 = mid - ql;
		if (dist1 == n1 - n1to0) { // less dist -> better match
			if (pos0 == -1) pos0 = ql; // any number in [ql, mid) is 0
			ql = mid;
		} else if (dist1 == n1 + n1to0) { // more dist -> worse match
			if (pos1 == -1) pos1 = ql; // any number in [ql, mid) is 1
			ql = mid;
		} else {
			// there are both 0 and 1 in that range
			qr = mid; // so we can search only in that range
		}
	}
	std::cout << "! " << 1+pos0 << ' ' << 1+pos1 << '\n';
	return 0;
}