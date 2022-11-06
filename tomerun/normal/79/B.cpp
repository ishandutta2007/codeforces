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

int n,m,k,t;

char* ans[] = {"Carrots", "Kiwis", "Grapes"};

int main()
{
    cin >> n >> m >> k >> t;
    vector<int> count(n, m);
    vector<vector<int> > waste(n);
    int a,b;
    for(int i = 0; i < k; ++i) {
        cin >> a >> b;
        --a;
        --b;
        waste[a].push_back(b);
        count[a]--;
    }
    for(int i = 0; i < n; ++i) {
        sort(waste[i].begin(), waste[i].end());
    }
    vector<int> accum(n);
    int prev = 0;
    for(int i = 1; i < n; ++i) {
        prev += count[i-1];
        accum[i] = prev;
    }
    for(int i = 0; i < t; ++i) {
        cin >> a >> b;
        --a;
        --b;
        int sum = accum[a];
        int wasteCount = 0;
        bool ws = false;
        for(int j = 0; j < waste[a].size(); ++j) {
            if (waste[a][j] > b) break;
            if (waste[a][j] == b) {
                ws = true;
                break;
            }
            ++wasteCount;
        }
        sum += b - wasteCount;
        if (ws) {
            cout << "Waste" << endl;
        }else{
            cout << ans[sum % 3] << endl;
        }
    }

}