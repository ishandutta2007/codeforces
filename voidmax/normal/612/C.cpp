/*
 - - - - - - - -
 
  *********
 ***********
 ***     ***
 ***     ***
 ***     ***
 ***********
 ***********
 ***     ***
 ***     ***
 ***     ***
 
 - - - - - - - -
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second

using namespace std;

string s;
vector <char> last;
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    For(i, 0, s.size()) {
        if (s[i] == ')' || s[i] == '>' || s[i] == '}' || s[i] == ']') {
            if (last.size() == 0) {
                cout << "Impossible" << endl;
                return 0;
            }
            if (!((last[(int)last.size() - 1] == '(' && s[i] == ')') ||
                  (last[(int)last.size() - 1] == '<' && s[i] == '>') ||
                  (last[(int)last.size() - 1] == '{' && s[i] == '}') ||
                  (last[(int)last.size() - 1] == '[' && s[i] == ']')))
                ++cnt;
            last.pop_back();
        } else {
            last.push_back(s[i]);
        }
    }
    if (last.size() != 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << cnt << endl;
}