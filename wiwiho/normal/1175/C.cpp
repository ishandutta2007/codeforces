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

#define MAX 1000000001

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for(int testcase = 0; testcase < t; testcase++){

        int n, k;
        cin >> n >> k;

        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        pair<int, int> distance = mp(MAX, MAX);

        for(int i = 0; i < n - k; i++){
            distance = min(distance, mp(a[i + k] - a[i], a[i] + (a[i + k] - a[i]) / 2));
        }

        cout << distance.second << "\n";

    }

    
    
    return 0;
}