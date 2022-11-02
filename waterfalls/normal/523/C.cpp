#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string S,T;

int main() {
    cin >> S >> T;
    int where = 0;
    int lastAt = T.size();
    for (int i=0;i<T.size();i++) {
        if (T[i]==S[where]) where+=1;
        if (where==S.size()) {
            lastAt = i;
            break;
        }
    }
    where = S.size()-1;
    int firstAt = 0;
    for (int i=T.size()-1;i>=0;i--) {
        if (T[i]==S[where]) where-=1;
        if (where==-1) {
            firstAt = i;
            break;
        }
    }
    if (lastAt>=firstAt) cout << "0\n";
    else cout << firstAt-lastAt << endl;

    return 0;
}