#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	map<int, map<int, map<int, int> > > P;
	for(int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		P[x][y][z] = i+1;
	}
	int last_tot = 0;
	for(auto ix = begin(P); ix != end(P); ix++) {
		int last = 0;
		for(auto iy = begin(ix->second); iy != end(ix->second); iy++) {
			map<int, int> & m = iy->second;
			while(m.size() >= 2) {
				cout << begin(m)->second << " ";
				m.erase(begin(m));
				cout << begin(m)->second << "\n";
				m.erase(begin(m));
			}
			if(!m.empty()) {
				if(!last) last = begin(m)->second;
				else {
					cout << last << " " << begin(m)->second << "\n";
					last = 0;
				}
			}
		}
		if(last) {
			if(!last_tot) last_tot = last;
			else {
				cout << last_tot << " " << last << "\n";
				last_tot = 0;
			}
		}
	}
}