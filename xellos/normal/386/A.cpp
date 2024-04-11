#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int winrar, winC =0, winC2 =0;
    for(int i =0; i < N; i++) {
        int p;
        cin >> p;
        if(winC < p) winC2 =winC, winC =p;
        else if(winC2 < p) winC2 =p;
        if(winC == p) winrar =i;}
    cout << winrar+1 << " " << winC2 << "\n";
    return 0;}