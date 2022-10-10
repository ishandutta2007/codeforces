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
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> V(N);
    for(int i =0; i < N; i++) cin >> V[i];
    sort(V.begin(),V.end());

    if(N == 1) {cout << "-1\n"; return 0;}
    if(V[N-1] == V[0]) {
        cout << "1\n" << V[0] << "\n";
        return 0;}
    if(N == 2) {
        if((V[0]+V[1])%2 == 0) cout << "3\n" << 2*V[0]-V[1] << " " << (V[0]+V[1])/2 << " " << 2*V[1]-V[0] << "\n";
        else cout << "2\n" << 2*V[0]-V[1] << " " << 2*V[1]-V[0] << "\n";
        return 0;}

    set<int> S;
    int d =V[1]-V[0], c =0;
    for(int i =1; i < N; i++) if(V[i]-V[i-1] != d) c++;
    if(c == 1) {
        for(int i =1; i < N; i++) if(V[i]-V[i-1] != d)
            if((V[i]-V[i-1]) == 2*d) S.insert((V[i]+V[i-1])/2);
        }
    if(c == 0) {
        S.insert(V[0]-d);
        S.insert(V[N-1]+d);}

    d =V[2]-V[1]; c =0;
    for(int i =1; i < N; i++) if(V[i]-V[i-1] != d) c++;
    if(c == 1) {
        for(int i =1; i < N; i++) if(V[i]-V[i-1] != d)
            if((V[i]-V[i-1]) == 2*d) S.insert((V[i]+V[i-1])/2);
        }
    if(c == 0) {
        S.insert(V[0]-d);
        S.insert(V[N-1]+d);}

    cout << S.size() << "\n";
    ALL_THE(S,it) {
        if(it != S.begin()) cout << " ";
        cout << *it;}
    cout << "\n";
    return 0;}

// look at my code
// my code is amazing