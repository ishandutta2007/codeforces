// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    if(N == 0) {
        cout << "0 " << M-1 << "\n";
        cout << "0 " << 0 << "\n";
        cout << "0 " << M << "\n";
        cout << "0 " << 1 << "\n";
        return 0;}
    if(M == 0) {
        cout << N-1 << " 0" << "\n";
        cout << 0 << " 0" << "\n";
        cout << N << " 0" << "\n";
        cout << 1 << " 0" << "\n";
        return 0;}

    double d1 =sqrt((N-1)*(N-1)+M*M), d2 =sqrt(N*N+(M-1)*(M-1));
    if(max(d1,d2)*2+soclose < max(N,M)+sqrt(N*N+M*M)) {
        cout << "0 0\n" << N << " " << M << "\n";
        if(N >= M) cout << "0 " << M << "\n" << N << " 0\n";
        else cout << N << " 0\n0 " << M << "\n";
        return 0;}
    if(d1 > d2+soclose) {
        cout << N-1 << " " << M << "\n";
        cout << "0 0" << "\n";
        cout << N << " " << M << "\n";
        cout << "1 0" << "\n";
        return 0;}
    cout << N << " " << M-1 << "\n";
    cout << "0 0" << "\n";
    cout << N << " " << M << "\n";
    cout << "0 1" << "\n";
    return 0;}

// look at my code
// my code is amazing