#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    vector<int> ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        bool bad = false;
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if ((x == 1) || (x == 3)) bad = true;
        }
        if (!bad) ans.push_back(i + 1);
    }   
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}