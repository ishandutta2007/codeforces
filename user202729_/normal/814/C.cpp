// problem c

#include <iostream>
#include <vector>
#include <string>

int len, nplan;
std::string str;
std::vector<std::vector<int>> maxnchar, result;
int cnt['z'+1];

int main() {
    std::cin >> len >> str >> nplan;
    maxnchar.resize('z'+1, std::vector<int>(len+1, 0));
    for (int i = 0; i < len; ++i) {
        for (char ch = 'a'; ch <= 'z'; ++ch) cnt[ch] = 0;
        for (int j = i; j < len; ++j) { // segment [i, j]
            int sublen = j-i+1;
            ++cnt[str[j]];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                maxnchar[ch][sublen] = std::max(maxnchar[ch][sublen], cnt[ch]);
            }
        }
    }
    result.resize('z'+1, std::vector<int>(len+1, 0));
    for (char ch = 'a'; ch <= 'z'; ++ch)
    for (int sl = 1; sl <= len; ++sl) {
        int &x = result[ch][sl];
        for (x = len; x > 0; --x) {
            if (x - maxnchar[ch][x] <= sl) break;
        }
        if (x == 0) std::cout << "erro";
    }
    while (nplan --> 0) {
        int npiece; char color;
        std::cin >> npiece >> color;
        std::cout << result[color][npiece] << "\n";
    }
}