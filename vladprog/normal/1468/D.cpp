#include<bits/stdc++.h>

using namespace std;

const int M = 2e5+1;

int t;
int n, m, a, b;
int s[M];

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> a >> b;
        for(int i = 0; i < m; ++i)
            cin >> s[i];
        sort(s, s+m);
        int t1, t2;
        if(a < b){
            t1 = b-a-1;
            t2 = a;
        }
        if(a > b){
            t1 = a-b-1;
            t2 = n-a+1;
        }
        int i;
        int mx = 0;
        for(i = 0; i < min(m, t1); ++i){
            mx = max(mx, s[i]);
            ++mx;
            if(mx > t1+t2)
                break;
        }
        cout << i << "\n";
    }
}