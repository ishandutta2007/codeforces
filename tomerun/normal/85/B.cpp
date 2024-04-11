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
typedef long long ll;

int k1,k2,k3,t1,t2,t3;
int n;
vector<int> c;

int main()
{
    scanf("%d %d %d", &k1, &k2, &k3);
    scanf("%d %d %d", &t1, &t2, &t3);
    scanf("%d", &n);
    int v;
    c.clear();
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v);
        c.push_back(v);
    }
    vector<ll> et1(min(k1, n), 0);
    vector<ll> et2(min(k2, n), 0);
    vector<ll> et3(min(k3, n), 0);
    int wpos = 0;
    vector<ll> st2;
    for(int i = 0; i < n; ++i) {
        if(c[i] >= et1[wpos]){
            et1[wpos] = c[i] + t1;
        }else{
            et1[wpos] += t1;
        }
        st2.push_back(et1[wpos]);
        ++wpos;
        if(wpos == et1.size()) {
            wpos = 0;
        }
    }
    wpos = 0;
    vector<ll> st3;
    for(int i = 0; i < n; ++i) {
        if(st2[i] >= et2[wpos]){
            et2[wpos] = st2[i] + t2;
        }else{
            et2[wpos] += t2;
        }
        st3.push_back(et2[wpos]);
        ++wpos;
        if(wpos == et2.size()) {
            wpos = 0;
        }
    }
    wpos = 0;
    vector<ll> end;
    for(int i = 0; i < n; ++i) {
        if(st3[i] >= et3[wpos]){
            et3[wpos] = st3[i] + t3;
        }else{
            et3[wpos] += t3;
        }
        end.push_back(et3[wpos]);
        ++wpos;
        if(wpos == et3.size()) {
            wpos = 0;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ans = max(ans, end[i] - c[i]);
    }
    cout << ans << endl;
    return 0;
}