#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int c,d;

int main()
{
    cin >> c >> d;
    bool f = true;
    while(d >= 2 && c >= 2 || c == 1 && d >= 12 || c == 0 && d >= 22) {
        if(f) {
            if(c >= 2) {
                c -= 2;
                d -= 2;
            }else if(c == 1) {
                c -= 1;
                d -= 12;
            }else{
                d -= 22;
            }
        }else{
            if(d >= 22) {
                d -= 22;
            }else if(d >= 12) {
                c -= 1;
                d -= 12;
            }else{
                c -= 2;
                d -= 2;
            }
        }
        f = !f;
    }
    cout << (f ? "Hanako" : "Ciel") << endl;
}