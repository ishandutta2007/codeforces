#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;

int main () {
    scanf ("%d", &n);
    if (n == 1) {
        printf ("0\n");
    }
    if (n == 2) {
        printf ("1\n");
        printf ("lea ebx, [eax + 1*eax]\n");
    }
    if (n == 3) {
        printf ("1\n");
        printf ("lea ebx, [eax + 2*eax]\n");
    }
    if (n == 4) {
        printf ("1\n");
        printf ("lea ebx, [4*eax]\n");
    }
    if (n == 5) {
        printf ("1\n");
        printf ("lea ebx, [eax + 4*eax]\n");
    }
    if (n == 6) {
        printf ("2\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
    }
    if (n == 7) {
        printf ("2\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
    }
    if (n == 8) {
        printf ("1\n");
        printf ("lea ebx, [8*eax]\n");
    }
    if (n == 9) {
        printf ("1\n");
        printf ("lea ebx, [eax + 8*eax]\n");
    }
    if (n == 10) {
        printf ("2\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
    }
    if (n == 11) {
        printf ("2\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*eax]\n");
    }
    if (n == 12) {
        printf ("2\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [4*ebx]\n");
    }
    if (n == 13) {
        printf ("2\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
    }
    if (n == 14) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 15) {
        printf ("2\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
    }
    if (n == 16) {
        printf ("2\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
    }
    if (n == 17) {
        printf ("2\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
    }
    if (n == 18) {
        printf ("2\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
    }
    if (n == 19) {
        printf ("2\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
    }
    if (n == 20) {
        printf ("2\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [4*ebx]\n");
    }
    if (n == 21) {
        printf ("2\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
    }
    if (n == 22) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 23) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [ecx + 8*eax]\n");
    }
    if (n == 24) {
        printf ("2\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
    }
    if (n == 25) {
        printf ("2\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
    }
    if (n == 26) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 27) {
        printf ("2\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
    }
    if (n == 28) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
    }
    if (n == 29) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
    }
    if (n == 30) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
    }
    if (n == 31) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 32) {
        printf ("2\n");
        printf ("lea ebx, [4*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
    }
    if (n == 33) {
        printf ("2\n");
        printf ("lea ebx, [4*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
    }
    if (n == 34) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 1*ecx]\n");
    }
    if (n == 35) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 2*ecx]\n");
    }
    if (n == 36) {
        printf ("2\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [4*ebx]\n");
    }
    if (n == 37) {
        printf ("2\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
    }
    if (n == 38) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 39) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ecx + 2*ecx]\n");
    }
    if (n == 40) {
        printf ("2\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
    }
    if (n == 41) {
        printf ("2\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
    }
    if (n == 42) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 43) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*eax]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 44) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*eax]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 45) {
        printf ("2\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
    }
    if (n == 46) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
    }
    if (n == 47) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*eax]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 48) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 49) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 50) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 51) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 2*ecx]\n");
    }
    if (n == 52) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 53) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
    }
    if (n == 54) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 55) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 56) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 57) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 58) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [eax + 2*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 59) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 60) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 61) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
    }
    if (n == 62) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 63) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 64) {
        printf ("2\n");
        printf ("lea ebx, [8*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
    }
    if (n == 65) {
        printf ("2\n");
        printf ("lea ebx, [8*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
    }
    if (n == 66) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [4*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 67) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [8*eax]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 68) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 69) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
    }
    if (n == 70) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 71) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [eax + 8*ebx]\n");
        printf ("lea eex, [ecx + 4*edx]\n");
    }
    if (n == 72) {
        printf ("2\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
    }
    if (n == 73) {
        printf ("2\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
    }
    if (n == 74) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 75) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 2*ecx]\n");
    }
    if (n == 76) {
        printf ("3\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 77) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 8*eax]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 78) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [edx + 2*edx]\n");
    }
    if (n == 79) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [ecx + 4*edx]\n");
    }
    if (n == 80) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 81) {
        printf ("2\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
    }
    if (n == 82) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 83) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 2*ecx]\n");
    }
    if (n == 84) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 85) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
    }
    if (n == 86) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 87) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ebx + 2*ecx]\n");
    }
    if (n == 88) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*eax]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 89) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*eax]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 90) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 91) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*eax]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 92) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
        printf ("lea eex, [ebx + 2*edx]\n");
    }
    if (n == 93) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 94) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [ecx + 4*edx]\n");
    }
    if (n == 95) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [ebx + 2*ecx]\n");
    }
    if (n == 96) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [4*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 97) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [4*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 98) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 99) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*eax]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 100) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 101) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
    }
    if (n == 102) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 103) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 104) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 105) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 106) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 107) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 108) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 109) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
    }
    if (n == 110) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 111) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 112) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [8*edx]\n");
    }
    if (n == 113) {
        printf ("3\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [ebx + 4*eax]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 114) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 115) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 116) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [ecx + 4*edx]\n");
    }
    if (n == 117) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 118) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ebx + 2*ecx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 119) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 2*ecx]\n");
        printf ("lea eex, [ecx + 2*edx]\n");
    }
    if (n == 120) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 121) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 122) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 123) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 124) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 4*ebx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 125) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
    }
    if (n == 126) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [edx + 8*edx]\n");
    }
    if (n == 127) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 2*ecx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 128) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 129) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 130) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 131) {
        printf ("3\n");
        printf ("lea ebx, [8*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 2*ecx]\n");
    }
    if (n == 132) {
        printf ("3\n");
        printf ("lea ebx, [4*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 133) {
        printf ("3\n");
        printf ("lea ebx, [4*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
    }
    if (n == 134) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 135) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 136) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 137) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 138) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 139) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [eax + 8*ebx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 140) {
        printf ("3\n");
        printf ("lea ebx, [4*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 141) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 8*ebx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 142) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 2*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 143) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 144) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 145) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 146) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 147) {
        printf ("3\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 2*ecx]\n");
    }
    if (n == 148) {
        printf ("3\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 149) {
        printf ("3\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
    }
    if (n == 150) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 151) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 152) {
        printf ("3\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 153) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 154) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 155) {
        printf ("3\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ebx + 2*ecx]\n");
    }
    if (n == 156) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 157) {
        printf ("3\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 158) {
        printf ("4\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [eax + 4*ebx]\n");
        printf ("lea eex, [ecx + 4*edx]\n");
    }
    if (n == 159) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ecx + 4*ebx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 160) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [4*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 161) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [4*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 162) {
        printf ("3\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 163) {
        printf ("3\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [eax + 2*ecx]\n");
    }
    if (n == 164) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 165) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
    }
    if (n == 166) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 167) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [ecx + 4*eax]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 168) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 169) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 170) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 171) {
        printf ("3\n");
        printf ("lea ebx, [eax + 8*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 172) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ebx + 2*ecx]\n");
        printf ("lea eex, [edx + 8*ecx]\n");
    }
    if (n == 173) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 174) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [ecx + 4*edx]\n");
    }
    if (n == 175) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 2*ecx]\n");
        printf ("lea eex, [edx + 4*edx]\n");
    }
    if (n == 176) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [8*edx]\n");
    }
    if (n == 177) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [eax + 8*edx]\n");
    }
    if (n == 178) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 179) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*eax]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
        printf ("lea eex, [eax + 2*edx]\n");
    }
    if (n == 180) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [4*ecx]\n");
    }
    if (n == 181) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
    }
    if (n == 182) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 183) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 184) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [ecx + 8*eax]\n");
        printf ("lea eex, [8*edx]\n");
    }
    if (n == 185) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
    }
    if (n == 186) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [ebx + 2*ecx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 187) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 2*ecx]\n");
        printf ("lea eex, [edx + 8*ecx]\n");
    }
    if (n == 188) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*eax]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [4*edx]\n");
    }
    if (n == 189) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 190) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [edx + 4*edx]\n");
    }
    if (n == 191) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*eax]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [ecx + 4*edx]\n");
    }
    if (n == 192) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 193) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 194) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 195) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [8*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 196) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
        printf ("lea eex, [4*edx]\n");
    }
    if (n == 197) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
        printf ("lea eex, [eax + 4*edx]\n");
    }
    if (n == 198) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [edx + 8*edx]\n");
    }
    if (n == 199) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [8*ebx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 200) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 201) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 202) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 203) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 204) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 2*ecx]\n");
        printf ("lea eex, [4*edx]\n");
    }
    if (n == 205) {
        printf ("3\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
    }
    if (n == 206) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [edx + 8*ecx]\n");
    }
    if (n == 207) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [edx + 2*edx]\n");
    }
    if (n == 208) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [8*edx]\n");
    }
    if (n == 209) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [eax + 8*edx]\n");
    }
    if (n == 210) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 211) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 212) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [4*edx]\n");
    }
    if (n == 213) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [eax + 4*edx]\n");
    }
    if (n == 214) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 215) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 216) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [8*ecx]\n");
    }
    if (n == 217) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
    }
    if (n == 218) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 219) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
    }
    if (n == 220) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 8*ebx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 221) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 2*ecx]\n");
        printf ("lea eex, [ecx + 4*edx]\n");
    }
    if (n == 222) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [edx + 2*edx]\n");
    }
    if (n == 223) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 8*ebx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 224) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [8*edx]\n");
    }
    if (n == 225) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 226) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [ecx + 4*ebx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 227) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 228) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 229) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
        printf ("lea eex, [eax + 4*edx]\n");
    }
    if (n == 230) {
        printf ("4\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [edx + 4*edx]\n");
    }
    if (n == 231) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
        printf ("lea eex, [ebx + 4*edx]\n");
    }
    if (n == 232) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [8*edx]\n");
    }
    if (n == 233) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [eax + 8*edx]\n");
    }
    if (n == 234) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [edx + 8*edx]\n");
    }
    if (n == 235) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 236) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [4*edx]\n");
    }
    if (n == 237) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [eax + 4*edx]\n");
    }
    if (n == 238) {
        printf ("4\n");
        printf ("lea ebx, [eax + 4*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 239) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 240) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
        printf ("lea eex, [8*edx]\n");
    }
    if (n == 241) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
        printf ("lea eex, [eax + 8*edx]\n");
    }
    if (n == 242) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 243) {
        printf ("3\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 8*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
    }
    if (n == 244) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [ebx + 4*ebx]\n");
        printf ("lea edx, [eax + 4*ecx]\n");
        printf ("lea eex, [4*edx]\n");
    }
    if (n == 245) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [eax + 8*ecx]\n");
        printf ("lea eex, [edx + 4*edx]\n");
    }
    if (n == 246) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ecx + 4*ecx]\n");
        printf ("lea eex, [ecx + 8*edx]\n");
    }
    if (n == 247) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 4*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
        printf ("lea eex, [ecx + 2*edx]\n");
    }
    if (n == 248) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [8*edx]\n");
    }
    if (n == 249) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [eax + 8*edx]\n");
    }
    if (n == 250) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [ebx + 2*ebx]\n");
        printf ("lea edx, [ebx + 8*ecx]\n");
        printf ("lea eex, [edx + 4*edx]\n");
    }
    if (n == 251) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ebx + 4*ecx]\n");
        printf ("lea eex, [ebx + 8*edx]\n");
    }
    if (n == 252) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [ecx + 8*ebx]\n");
        printf ("lea eex, [edx + 8*edx]\n");
    }
    if (n == 253) {
        printf ("4\n");
        printf ("lea ebx, [eax + 2*eax]\n");
        printf ("lea ecx, [eax + 2*ebx]\n");
        printf ("lea edx, [ecx + 8*ecx]\n");
        printf ("lea eex, [eax + 4*edx]\n");
    }
    if (n == 254) {
        printf ("5\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 1*ebx]\n");
        printf ("lea edx, [eax + 2*ecx]\n");
        printf ("lea eex, [edx + 8*edx]\n");
        printf ("lea efx, [ebx + 4*eex]\n");
    }
    if (n == 255) {
        printf ("4\n");
        printf ("lea ebx, [eax + 1*eax]\n");
        printf ("lea ecx, [eax + 8*ebx]\n");
        printf ("lea edx, [ecx + 2*ecx]\n");
        printf ("lea eex, [edx + 4*edx]\n");
    }
    re 0;   
}