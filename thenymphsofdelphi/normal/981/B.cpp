#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
using namespace std;

vector< pair<int, int> > a, b;

int main(){
    long long n, m, idx, val, sum = 0;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> idx >> val;
        a[i] = mp(idx, val);
    }
    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; i++){
        cin >> idx >> val;
        b[i] = mp(idx, val);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long idxa = 0, idxb = 0;
    while (idxa < n && idxb < m){
        if (a[idxa].fi < b[idxb].fi){
            sum += a[idxa].se;
            idxa++;
        }
        else if (a[idxa].fi > b[idxb].fi){
            sum += b[idxb].se;
            idxb++;
        }
        else{
            if (a[idxa].se > b[idxb].se){
                sum += a[idxa].se;
            }
            else{
                sum += b[idxb].se;
            }
            idxa++;
            idxb++;
        }
    }
    for (; idxa < n; idxa++){
        sum += a[idxa].se;
    }
    for (; idxb < m; idxb++){
        sum += b[idxb].se;
    }
    cout << sum;
}