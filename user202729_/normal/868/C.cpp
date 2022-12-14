#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif // _GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <cassert>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int nproblem, nteam; std::cin >> nproblem >> nteam;
	std::vector<std::vector<int>> data (nteam, std::vector<int>(nproblem));
	for (int problem = 0; problem < nproblem; ++problem)
		for (int team = 0; team < nteam; ++team)
			std::cin >> data[team][problem];
    for (int team = 0; team < nteam; ++team) {
		for (int problem = 0; problem < nproblem; ++problem) {
			if (!data[team][problem]) goto nextteam;
		}
		std::cout << "NO\n"; return 0; // there exist a team know all problems
		nextteam:;
	}
    std::vector<char> teammasks (1 << nteam, false);
//    std::vector<int> problemmask (nproblem);
	for (int problem = 0; problem < nproblem; ++problem) {
		int nteamknowthisproblem = 0, teammask = 0;
		for (int team = 0; team < nteam; ++team) {
			nteamknowthisproblem += data[team][problem];
			teammask = (teammask << 1) | data[team][problem];
		}
//		problemmask[problem] = teammask;
		assert(nteamknowthisproblem == __builtin_popcount(teammask));
		if (nteamknowthisproblem <= 1) { // 0 -> obvious. 1 -> because of the above
			std::cout << "YES\n"; return 0;
		}
		teammasks[teammask] = true;
    }
    for (int mask1 = 0; mask1 < teammasks.size(); ++mask1)
	for (int mask2 = 0; mask2 < teammasks.size(); ++mask2) {
		if (mask1 != mask2 && (mask1 & mask2) == 0 && teammasks[mask1] && teammasks[mask2]) {
			std::cout << "YES\n"; return 0; // choose those 2 problems
		}
	}
	std::cout << "NO\n";
}