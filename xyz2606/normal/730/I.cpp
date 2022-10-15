#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

const int N = 3333;
const int INF = 1e9 + 7;

using namespace std;

struct Player {
	int id, a, b;
	Player(int id, int a, int b) : id(id), a(a), b(b) {}
	bool friend operator <(const Player &a, const Player &b) {
		return a.a - a.b > b.a - b.b;
	}
};

int n, p, s;
vector<Player> players;
long long ans = -1;
vector<int> std_program, std_sports;
void update(const vector<pair<int, int> > &pro, const vector<pair<int, int> > &spo, long long total) {
	if (ans == -1 || total > ans) {
		ans = total;
		std_program.clear();
		std_sports.clear();
		for (int i = 0; i < p; i++) std_program.push_back(pro[i].second);
		for (int i = 0; i < s; i++) std_sports.push_back(spo[i].second);
	}
}

int main() {
	scanf("%d %d %d", &n, &p, &s);
	{
		static int a[N], b[N];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
			players.push_back(Player(i, a[i], b[i]));
		}
	}
	sort(players.begin(), players.end());
	/*for (int i = 0; i < players.size(); i++) {
		printf("%d %d\n", players[i].a, players[i].b);
	}*/
	for (int i = 0, j; i < n; i = j) {
		int delta = players[i].a - players[i].b;
		vector<pair<int, int> > mid;
		for (j = i; j < n && players[j].a - players[j].b == delta; j++) {
			mid.push_back(make_pair(players[j].a, players[j].id));
		}
		sort(mid.begin(), mid.end());
		reverse(mid.begin(), mid.end());
		vector<pair<int, int> > program, sports;
		for (int k = 0; k < i; k++) {
			program.push_back(make_pair(players[k].a, players[k].id));
		}
		for (int k = program.size(); k <= p; k++) {
			program.push_back(make_pair(-INF, -1));
		}
		for (int k = j; k < n; k++) {
			sports.push_back(make_pair(players[k].b, players[k].id));
		}
		for (int k = sports.size(); k <= s; k++) {
			sports.push_back(make_pair(-INF, -1));
		}
		sort(program.begin(), program.end());
		sort(sports.begin(), sports.end());
		reverse(program.begin(), program.end());
		reverse(sports.begin(), sports.end());
		program.resize(p);
		sports.resize(s);
		reverse(program.begin(), program.end());
		reverse(sports.begin(), sports.end());
		long long total = 0;
		for (int k = 0; k < p; k++) total += program[k].first;
		for (int k = 0; k < s; k++) total += sports[k].first;
		
		update(program, sports, total);
		for (int k = 0, ptr_p = 0, ptr_s = 0; k < mid.size() && (ptr_p < p || ptr_s < s); k++) {
			if (ptr_s == s || ptr_p < p && mid[k].first - program[ptr_p].first > mid[k].first - delta - sports[ptr_s].first) {
				total += mid[k].first - program[ptr_p].first;
				program[ptr_p] = mid[k];
				ptr_p++;
			} else {
				total += mid[k].first - delta - sports[ptr_s].first;
				sports[ptr_s] = mid[k];
				sports[ptr_s].first -= delta;
				ptr_s++;
			}
			update(program, sports, total);
		}
	}
	cout << ans << endl;
	for (int i = 0; i < p; i++) {
		printf("%d%c", std_program[i] + 1, i + 1 == std_program.size() ? '\n' : ' ');
	}
	for (int i = 0; i < s; i++) {
		printf("%d%c", std_sports[i] + 1, i + 1 == std_sports.size() ? '\n' : ' ');
	}
	return 0;
}