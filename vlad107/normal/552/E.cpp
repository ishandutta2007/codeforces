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

#define mp make_pair
#define ull unsigned long long

using namespace std;

const int N = 6666;

pair<ull, ull> a[N], b[N];
int ca, cb;

int main() {
    // freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    a[0]=mp(0,1);
    for (int i = 0; i + 1 < s.size(); i += 2) {
        int x = s[i] - '0';
        if (s[i + 1] == '+') {
            a[ca+1]=mp(a[ca].first+a[ca].second*x,1);
        } else {
            a[ca+1]=mp(a[ca].first,a[ca].second*x);
        }
        ++ca;
    }
    int x = s[(int)s.size()-1]-'0';
    ull ans = a[ca].first+a[ca].second*x;
    cb=ca;
    b[cb]=mp(0,1);
    for (int i = (int)s.size() - 1; i > 0; i -= 2) {
        int x = s[i] - '0';
        if (s[i - 1] == '+') {
            b[cb-1]=mp(b[cb].first+b[cb].second*x,1);
        } else {
            b[cb-1]=mp(b[cb].first,b[cb].second*x);
        }
        --cb;
    }
    cb=ca;
    // for (int i = 0; i <= ca; i++) {
    //  cerr << "a[" << i << "]=(" << a[i].first << ", " << a[i].second << ")" << endl;
    //  cerr << "b[" << i << "]=(" << b[i].first << ", " << b[i].second << ")" << endl;
    // }
    // for (int i = 0; i <= ca; i++) {
    //  cerr << b[i].first << " " << b[i].second << endl;
    // }
    for (int i = 0; i < ca; i++) {
        pair<ull, ull> cur = mp(0,1);
        for (int j = i; j<ca; j++) {////
            int x=(s[2*j]-'0');
            pair<ull,ull> ncur;
            if (s[2*j+1]=='+') {
                cur=mp(cur.first+cur.second*x,1);
            } else {
                cur=mp(cur.first,cur.second*x);
            }
            // cerr << i << " " << j << " --- " << "(" << cur.first << ", " << cur.second << ")" << endl; 
            int y=(s[2*j+2]-'0');
            ncur = mp(a[i].first,(cur.first+cur.second*y)*a[i].second);
            ans=max(ans,ncur.first+ncur.second*b[j+1].second+b[j+1].first);
        }
    }
    cout<<ans<<endl;
}