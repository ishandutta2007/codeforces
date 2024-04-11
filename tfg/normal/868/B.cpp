#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int h, m, s, t1, t2;
	std::cin >> h >> m >> s >> t1 >> t2;
	t1 *= 3600;
	t2 *= 3600;
	std::vector<int> pts;
	int tot_s = s + m * 60 + h * 3600;
	int HPT = tot_s;
	int MPT = 12 * (tot_s % 3600);
	int SPT = 12 * (tot_s % 60) * 60;
	pts.push_back(HPT - 12 * 3600);
	pts.push_back(HPT);
	pts.push_back(HPT + 12 * 3600);
	pts.push_back(SPT - 12 * 3600);
	pts.push_back(SPT);
	pts.push_back(SPT + 12 * 3600);
	pts.push_back(MPT - 12 * 3600);
	pts.push_back(MPT);
	pts.push_back(MPT + 12 * 3600);
	std::sort(pts.begin(), pts.end());
	for(int i = 0; i + 1 < pts.size(); i++) {
		if(pts[i] < t1 && t1 < pts[i + 1]) {
			//std::cout << "got range (" << pts[i] << ", " << pts[i + 1] << ")\n";
			while(t2 < pts[i])
				t2 += 12 * 3600;
			while(t2 > pts[i + 1])
				t2 -= 12 * 3600;
			if(pts[i] < t2 && t2 < pts[i + 1]) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
			return 0;
		}
	}
	std::cout << "NO\n";
}