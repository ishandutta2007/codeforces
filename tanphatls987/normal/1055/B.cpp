#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N = 1e5 + 10;

int n, test, l;
long long a[N];
int main() {
    cin >> n >> test >> l;
    

    int seg = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        seg += a[i] > l;
    }
    for(int i = 2; i <= n; i++) {
        if (a[i] > l && a[i - 1] > l) seg--;
    }
    while (test--){
        int type, pos, len;
        cin >> type;
        if (type == 0) cout << seg << '\n';
        else {
            cin >> pos >> len;
            bool pass = (a[pos] <= l && a[pos] + len > l);
            a[pos] += len;
            if (pass) {
                seg++;
                if (a[pos - 1] > l) seg--;
                if (a[pos + 1] > l) seg--;
            }
        }
    }

}