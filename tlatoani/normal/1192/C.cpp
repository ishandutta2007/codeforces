//
// Created by Danny Mittal on 7/26/19.
//

#include <iostream>
#include <unordered_set>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

const uint64_t MOD = 998244353;

struct mint {
    uint64_t val;

    mint(): val(0) {}
    mint(uint64_t val): val(val) {}
};

istream& operator >>(istream& in, mint& k) {
    in >> k.val;
    k.val %= MOD;
    return in;
}

ostream& operator <<(ostream& out, mint k) {
    out << k.val;
    return out;
}

mint operator +(mint a, mint b) {
    return mint((a.val + b.val) % MOD);
}

mint operator -(mint k) {
    return mint((MOD - k.val) % MOD);
}

mint operator -(mint a, mint b) {
    return mint((MOD + a.val - b.val) % MOD);
}

mint operator *(mint a, mint b) {
    return mint((a.val * b.val) % MOD);
}

void operator +=(mint& a, mint b) {
    a.val += b.val;
    a.val %= MOD;
}

void operator -=(mint& a, mint b) {
    a.val += MOD - b.val;
    a.val %= MOD;
}

void operator *=(mint& a, mint b) {
    a.val *= b.val;
    a.val %= MOD;
}

mint operator^(mint b, int64_t e) {
    e %= MOD - 1;
    if (e < 0) {
        e += MOD - 1;
    }
    mint res(1);
    for (; e; e >>= 1) {
        if (e & 1) {
            res *= b;
        }
        b *= b;
    }
    return res;
}

void operator ^=(mint& b, int64_t e) {
    b = b ^ e;
}

mint operator /(mint a, mint b) {
    return a * (b ^ -1);
}

void operator /=(mint& a, mint b) {
    a *= b ^ -1;
}

const mint M0 = mint(0);
const mint M1 = mint(1);
const mint M2 = mint(2);
const mint M4 = mint(4);
const mint M8 = mint(8);

int charIx(char chara) {
    if (chara <= '9') {
        return chara - '0';
    } else if (chara <= 'Z') {
        return 10 + (chara - 'A');
    } else {
        return 36 + (chara - 'a');
    }
}

int main() {
    int n;
    cin >> n;
    unordered_set<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.insert(word);
        reverse(word.begin(), word.end());
        words.insert(word);
    }
    mint answer = M0;
    for (int l = 3; l <= 10; l++) {
        mint edges[62][62];
        for (string word : words) {
            if (word.length() == l) {
                edges[charIx(word[0])][charIx(word[word.length() - 1])] += M1;
            }
        }
        mint tris[62][62][62];
        for (int a = 0; a < 62; a++) {
            for (int b = a; b < 62; b++) {
                for (int c = 0; c < 62; c++) {
                    mint res;
                    for (int d = 0; d < 62; d++) {
                        res += edges[a][d] * edges[b][d] * edges[c][d];
                    }
                    tris[a][b][c] = res;
                    tris[c][a][b] = res;
                    tris[b][c][a] = res;
                    tris[a][c][b] = res;
                    tris[c][b][a] = res;
                    tris[b][a][c] = res;
                }
            }
        }
        for (int k = 0; k < 62; k++) for (int x = k + 1; x < 62; x++)
            for (int p = k + 1; p < 62; p++) for (int q = x + 1; q < 62; q++) {
                if (p == x || p == q) {
                    continue;
                }
                answer += M8 * tris[k][x][p] * tris[x][p][q] * tris[p][q][k] * tris[q][k][x];
            }
        for (int k = 0; k < 62; k++) for (int x = 0; x < 62; x++) for (int q = x + 1; q < 62; q++) {
            if (x == k || q == k) {
                continue;
            }
            answer += M4 * tris[k][x][k] * tris[x][k][q] * tris[k][q][k] * tris[q][k][x];
        }
        for (int k = 0; k < 62; k++) for (int p = 0; p < 62; p++) for (int q = p + 1; q < 62; q++) {
            if (p == k || q == k) {
                continue;
            }
            answer += M8 * tris[k][k][p] * tris[k][p][q] * tris[p][q][k] * tris[q][k][k];
        }
        for (int k = 0; k < 62; k++) for (int x = k + 1; x < 62; x++) {
            answer += M4 * tris[k][x][k] * tris[x][k][x] * tris[k][x][k] * tris[x][k][x];
        }
        for (int k = 0; k < 62; k++) for (int p = k + 1; p < 62; p++) {
            answer += M2 * tris[k][k][p] * tris[k][p][p] * tris[p][p][k] * tris[p][k][k];
        }
        for (int ka = 0; ka < 62; ka++) for (int p = 0; p < 62; p++) {
            if (ka == p) {
                continue;
            }
            answer += M4 * tris[ka][ka][ka] * (tris[ka][ka][p] ^ 3);
        }
        for (int k = 0; k < 62; k++) {
            answer += tris[k][k][k] ^ 4;
        }
    }
    cout << answer << endl;
}