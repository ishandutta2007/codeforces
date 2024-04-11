#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int W,H;
string one[100];
string two[100];
string three[200];

int main() {
    cin >> W >> H;
    for (int i=0;i<H;i++) cin >> one[i];
    for (int i=0;i<H;i++) for (int j=0;j<W;j++) two[j]+=one[i][j];
    for (int i=0;i<W;i++) {
        for (int j=0;j<H;j++) {
            char what = two[i][j];
            three[2*i]+=what;
            three[2*i]+=what;
            three[2*i+1]+=what;
            three[2*i+1]+=what;
        }
    }
    for (int i=0;i<2*W;i++) cout << three[i] << endl;

    return 0;
}