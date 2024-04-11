#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;

int main() {
    int a, b; cin >> a >> b;
    set<int> x, y;
    int aSum = 0, bSum = 0;
    bool taken[100000];
    memset(taken, 0, sizeof(taken));
    for(int i=1;i<100000;i++) {
        if(aSum==a) break;
        if(aSum+i<=a) {
            taken[i] = true;
            x.insert(i);
            aSum+=i;
        }
        else {
            int repl = i-(a-aSum);
            taken[repl] = false;
            taken[i] = true;
            x.erase(repl);
            x.insert(i);
            aSum-=repl;
            aSum+=i;
        }
    }
    for(int i=1;i<100000;i++) {
        if(taken[i]) continue;
        if(bSum+i<=b) {
            y.insert(i);
            bSum+=i;
        }
    }
    cout << x.size() << "\n";
    for(auto &it : x) cout << it << " ";
    cout << "\n";
    cout << y.size() << "\n";
    for(auto &it : y) cout << it << " ";
    cout << "\n";
}