//http://codeforces.com/problemset/problem/611/D

#include <iostream>
#include <string>
#include <vector>

int len;
std::string str;
std::vector<std::vector<int>> lcp, result; // [begin index][last length]

const int mod = 1000000007;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main() {
    std::cin >> len >> str;
    if (str.length() != len) {
        return 123;
    }

    lcp.resize(1+len, std::vector<int>(1+len));
    for (int i = 0; i <= len; ++i) lcp[i][len] = lcp[len][i] = 0;
    // lcp with empty string -> 0
    for (int b1 = len-1; b1 >= 0; --b1) {
        for (int b2 = len-1; b2 >= 0; --b2) {
            if (str[b1] != str[b2]) lcp[b1][b2] = 0;
            else lcp[b1][b2] = 1 + lcp[b1+1][b2+1];
        }
    }

    result.resize(len+1);
    for (int i=0; i<len; ++i) {
        result[i].resize(i+1,0);
    }

    result[len].resize(len+1, 1); // if i=len then result[i]=1


    for (int bi=len-1; bi>=0; --bi) {  // begin index. O(n)
        if (str[bi] == '0') continue;

        //std::cout << " ------------- bi = " << bi << "\n";

        int sum = 0, fl = std::min(bi, len-bi);
        for (int nl = fl+2; nl <= len - bi; ++nl) {
            add(sum, result[bi+nl][nl]);
            //std::cout << "sum add " << nl << "\n";
        }

        for (int ll = fl; ll> 0; --ll) { //
            result[bi][ll] = 0;
            // if (bi + ll > len) continue; // the last can't constitute a larger number
            if (bi + ll > len) std::cout << "ERROR!\n";

            {
                int l = lcp[bi-ll][bi];
                if (l < ll && str[bi-ll+l] < str[bi+l])
                    result[bi][ll] += result[bi+ll][ll];
            }
            if (bi + ll + 1 <= len) {
                add(sum, result[bi+ll+1][ll+1]);
                //std::cout << "sum add " << ll+1 << "\n";
            }
            add(result[bi][ll], sum);
            //std::cout << " ++++++ with ll=" << ll << "->result=" << result[bi][ll] << "\n";

            //std::cout << "bi=" << bi << ",ll=" << ll << ",res=" << result[bi][ll] << "\n";
        }
    }

/*
    for (int bi = 0; bi < result.size(); ++bi) {
        std::cout << " --------------- bi =" << bi << "\n";
        for (int ll = 0; ll < result[bi].size(); ++ll) {
            std::cout << "ll=" << ll << ", res=" << result[bi][ll] << "\n";
        }
    }
*/

    int res = 0;
    for (int fl = 1; fl <= len; ++fl) add(res, result[fl][fl]);
    std::cout << res << "\n"; // O(n^2)
}