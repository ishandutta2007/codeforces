#include <bits/stdc++.h>

using namespace std;

char str[100];
const int N = 2010;
int state[N];
int can_arrange[N][N];

int readState() {
    int result = 0;
    scanf(" %s", &str);
    for (int i = 0; i < 7; i++) {
        result = (2 * result + (str[i] == '1' ? 1 : 0));
    }
    return result;
}

int numberStates[] = {
    0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011 
};

int getBit(int x, int p) {
    return (x >> p) & 1;
}

int tryTurnOnBits(int state, int number) {
    int d = 0;
    for (int i = 0; i < 7; i++) {
        if (getBit(state, i) == 1 && getBit(numberStates[number], i) == 0) {
            return -1;
        }
        d += abs(getBit(state, i) - getBit(numberStates[number], i));
    }
    return d;
}

const int D = (1 << 7);
int table[D][10];

int main() {
    for (int i = 0; i < D; i++) {
        for (int d = 0; d < 10; d++) {
            table[i][d] = tryTurnOnBits(i, d);
        }
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        state[i] = readState();
    }
    can_arrange[n][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int s = 0; s <= k; s++) {
            for (int d = 0; d < 10; d++) {
                int t = table[state[i]][d];
                if (t == -1 || t > s) {
                    continue;
                }
                can_arrange[i][s] |= can_arrange[i + 1][s - t];
            }
        }
    }
    if (!can_arrange[0][k]) {
        puts("-1");
        return 0;
    }
    auto number = string();
    for (int i = 0; i < n; i++) {
        for (int d = 9; d >= 0; d--) {
            int t = table[state[i]][d];
            if (t == -1 || t > k) {
                continue;
            }
            if (!can_arrange[i + 1][k - t]) {
                continue;
            }
            number.push_back('0' + d);
            k -= t;
            break;
        }
    }
    printf("%s\n", number.c_str());
    return 0;
}