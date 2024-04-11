#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    cout << string(300, '.') << endl;
    for (char c: s) {
        cout << ".." << string(296, 'X') << ".." << endl;

        cout << ".X";
        for (int i=0;i<=c;i++) cout << 'X';
        for (int i=c+1;i<298;i++) cout << '.';
        cout << endl;

        cout << ".X" << string(298, '.') << endl;

        cout << string(300, '.') << endl;

        cout << "..";
        for (int i=0;i<c-1;i++) cout << "X.";
        for (int i=0;i<300-(int) 2*c;i++) cout << ".";
        cout << endl;

        cout << string(300, '.') << endl;

        cout << ".X" << string(298, '.') << endl;

        cout << ".XX" << string(297, '.') << endl;

        cout << string(300, '.') << endl;
    }
}