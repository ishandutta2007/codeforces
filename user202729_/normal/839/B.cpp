#include <iostream>
//#include <cassert>

bool possible(int nGroup2, int nGroup4, int nSeat2, int nSeat4) {
    int nGroup4ToSeat4 = std::min(nGroup4, nSeat4);
    nGroup4 -= nGroup4ToSeat4;
    nSeat4 -= nGroup4ToSeat4;
    if (nGroup4 == 0) {
        // nSeat4 != 0. 2 seat4 => 3 seat2
        int nConvertSeat4Group = nSeat4 / 2;
        nSeat4 -= 2 * nConvertSeat4Group;
        nSeat2 += nConvertSeat4Group * 3;
        if (nSeat4 == 1) {++nSeat2; nSeat4 = 0;}
//        assert (nSeat4 == 0);
        return nGroup2 <= nSeat2;
    } else {
        // nSeat4 == 0
        nGroup2 += 2*nGroup4; nGroup4 = 0;
        // now nGroup4 == 0
        return nGroup2 <= nSeat2;
    }
}

int main() {
    int nRow, nGroup, nGroup4 = 0, nGroupOdd = 0, nGroup2 = 0, a_i;
    std::cin >> nRow >> nGroup;
    for (int i = 0; i < nGroup; ++i) {
        std::cin >> a_i;
        nGroup4 += a_i / 4;
        a_i %= 4;
        if (a_i >= 2) {++nGroup2; a_i -= 2;}
        if (a_i) ++nGroupOdd;
    }
    std::cout << ((nGroupOdd > nRow ? possible(nGroup2, nGroup4, 4 * nRow - nGroupOdd, 0) : possible(nGroup2, nGroup4, nGroupOdd + 2 * nRow, nRow - nGroupOdd)) ? "YES\n" : "NO\n");
}