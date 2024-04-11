#include <bits/stdc++.h>

#define iter(a) a.begin(), a.end()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(iter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a) bool pvaspace=false;

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define MAX 1000000000

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    if(x + z > y && x > y && x > y + z){
        cout << "+\n";
    }
    else if(y + z > x && y > x && y > x + z){
        cout << "-\n";
    }
    else if(x == y && z == 0){
        cout << "0\n";
    }
    else{
        cout << "?\n";
    }

    
    return 0;
}