#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int getmn(vector<int> a) {
    int ret = 0, lst = -1e9;
    int n = a.size();
    for(int i = 0; i < n; ++i) {
        if(abs(a[i] - lst) > 1) {
            lst = a[i] + 1;
            ret++;
        }
    }
    return ret;
}
int getmx(vector<int> a) {
    map<int, int> mp;
    for(int i : a) {
        if(!mp.count(i - 1)) mp[i - 1] = 1;
        else if(!mp.count(i)) mp[i] = 1;
        else mp[i+1] = 1;
    }
    return mp.size();
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    cout << getmn(a) << " " << getmx(a) << endl;
}