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
#include <cstdlib>

using namespace std;
string s;
int n;
const int INF = 100000000;

int main()
{
    cin >> s >> n;
    vector<bool> start(s.size());
    vector<int> end(s.size(), INF);
    for(int i = 0; i < n; ++i) {
        string b;
        cin >> b;
        string::iterator cur = s.begin();
        while(true) {
            cur = search(cur, s.end(), b.begin(), b.end());
            if(cur == s.end()) {
                break;
            }
            start[cur - s.begin()] = true;
            int ep =cur - s.begin() + b.size() - 1;
            end[ep] = min(end[ep], (int)b.size());
            ++cur;
        }
    }
    vector<int> ep;
    vector<int> elen;
    for(int i = 0; i < s.size(); ++i) {
        if(end[i] != INF){
            ep.push_back(i);
            elen.push_back(end[i]);
        }
    }
    int max = 0;
    int pos = 0;
    for(int i = 0; i < s.size(); ++i) {
        if((i == 0 || start[i-1])) {
            vector<int>::iterator last = upper_bound(ep.begin(), ep.end(), i-1);
            int l = s.size() - i;
            while(last != ep.end()) {
                if(*last - elen[last - ep.begin()] + 1 >= i){
                    l = *last - i;
                    break;
                }
                ++last;
            }
//          cout << i << " " << l << endl;
            if(l > max) {
                max = l;
                pos = i;
            }
        }
    }
    cout << max << " " << pos << endl;
}