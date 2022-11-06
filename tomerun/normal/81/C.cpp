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

vector<char> ans;
vector<int> t;
int n,a,b;

void solve(){
    if(a == b) {
        for(int i = 0; i < a; ++i) {
            ans.push_back('1');
        }
        for(int i = 0; i < a; ++i) {
            ans.push_back('2');
        }
        return;
    }
    if(a < b) {
        ans.assign(n, '2');
        vector<int> s;
        for(int i = 0; i < n; ++i) {
            s.push_back((t[i] << 24) + n-i);
        }
        sort(s.begin(), s.end());
        for(int i = 0; i < a; ++i) {
            int pos = n-(s[n-1-i] % (1 << 24));
            ans[pos] = '1';
        }
    }else{
        ans.assign(n, '1');
        vector<int> s;
        for(int i = 0; i < n; ++i) {
            s.push_back((t[i] << 24) + i);
        }
        sort(s.begin(), s.end());
        for(int i = 0; i < b; ++i) {
            int pos = s[n-1-i] % (1 << 24);
            ans[pos] = '2';
        }
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    for(int i = 0; i < n; ++i) {
        int v;
        scanf("%d", &v);
        t.push_back(v);
    }
    solve();
    for(int i = 0; i < n-1; ++i) {
        printf("%c ", ans[i]);
    }
    printf("%c\n", ans[n-1]);
    return 0;
}