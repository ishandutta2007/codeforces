#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, d;
    cin >> n >> d;

    int s[n], a[n];

    vector<tuple<int,int,int>> ord;

    for(int i = 0; i < n; i++){
        cin >> s[i] >> a[i];
        ord.push_back({max(a[i], s[i]), s[i], a[i]});
    }

    int curr_d = d;
    int ans = 0;

    sort(ord.begin(), ord.end());

    for(int i = 0; i < ord.size(); i++){
        int d, s, a;
        tie(d, s, a) = ord[i];

        // cout << "we have " << a << " " << s << endl;

        if(s>=curr_d){
            ans++;
            curr_d = max(curr_d, a);
        }
    }

    cout << ans << endl;

    return 0;
}