#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    ll k;
    cin >> n >> k;
    bool work = true;
    work = work&&(k>n*1LL*(n+1)/2);
    if(!work) {
        if(k==n*1LL*(n+1)/2) {
            cout << n*1LL*(n+1)/2 << endl;
            for(int i=0;i<n;i++) cout << i+1 << " ";
            cout << endl;
            for(int i=0;i<n;i++) cout << i+1 << " ";
        }
        else cout << -1 << endl;
        return 0;
    }
    if(n%2==1) work = work&&(k<=(3*n-1)*1LL*(n+1)/4);
    else work = work&&(k<=(3*n+2)*1LL*n/4);
    if(!work) {
        if(n%2) cout << (3*n-1)*1LL*(n+1)/4 << endl;
        else cout << (3*n+2)*1LL*n/4 << endl;
        for(int i=0;i<n;i++) cout << i+1 << " ";
        cout << endl;
        for(int i=0;i<n;i++) cout << n-i << " ";
        cout << endl;
        return 0;
    }
    vector<int> vals;
    vals.push_back(n-1);
    while(vals[vals.size()-1]>2) {
        vals.push_back(vals[vals.size()-1]-2);
    }
    ll curr = n*1LL*(n+1)/2;
    int start = n+1;
    int sMove = 0;
    for(int i=0;i<vals.size();i++) {
        --start;
        curr+=vals[i];
        if(curr>=k) {
            curr-=vals[i];
            sMove = k-curr;
            break;
        }
    }
    vector<int> q;
    int idx = 0;
    for(int i=n;i>start;i--) {
        q.push_back(i);
    }
    for(int i=1;i<=start;i++) {
        q.push_back(i);
        if(i==start) idx = q.size()-1;
    }
    while(idx>=start) {
        swap(q[idx],q[idx-1]);
        idx--;
    }
    for(int i=0;i<sMove;i++) {
        swap(q[idx],q[idx-1]);
        idx--;
    }
    cout << k << endl;
    for(int i=0;i<n;i++) cout << i+1 << " ";
    cout << endl;
    for(auto &it : q) cout << it << " ";
}