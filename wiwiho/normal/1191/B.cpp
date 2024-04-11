#include <bits/stdc++.h>
 
#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define fr front()
#define po pop()
#define ba back()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
 
//#define TEST
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
const ll MOD = 1000000007;
const ll MAX = 1000000001;
 
int main(){
 
    StarBurstStream
 
    string a[3];
    cin >> a[0] >> a[1] >> a[2];
 
    if(a[0] == a[1] && a[1] == a[2]){
        cout << "0\n";
        return 0;
    }
 
    if(a[0][1] == a[1][1] && a[1][1] == a[2][1]){
        sort(a, a + 3);
        if(a[0][0] + 2 == a[2][0] && a[0][0] + 1 == a[1][0]){
            cout << "0\n";
            return 0;
        }
    }
    
    if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2]){
        cout << "1\n";
        return 0;
    }
 
    if(a[0][1] == a[1][1] && (abs(a[0][0] - a[1][0]) <= 2)){
        cout << "1\n";
        return 0;
    }
 
    if(a[1][1] == a[2][1] && (abs(a[1][0] - a[2][0]) <= 2)){
        cout << "1\n";
        return 0;
    }
 
    if(a[0][1] == a[2][1] && (abs(a[0][0] - a[2][0]) <= 2)){
        cout << "1\n";
        return 0;
    }
 
    cout << "2\n";
 
 
    return 0;
}