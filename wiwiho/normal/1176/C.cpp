#include <bits/stdc++.h>

#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define MAX 1000000001

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int s[6] = {4, 8, 15, 16, 23, 42};

    vector<int> a(n);
    vector<int> count(7);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < 6; j++){
            if(a[i] != s[j]){
                continue;
            }
            if(j > 0 && count[j] < 1){
                break;;
            }
            count[j + 1]++;
            count[j]--;
            break;
        }
    }

    cout << n - count[6] * 6 << "\n";
    return 0;
}