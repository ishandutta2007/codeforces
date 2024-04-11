#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;
int a[100001];
int n;
bool num(int x) {
    int cnt = 0;
    for(int i=0;i<x;i++) {
        if(a[i]<a[n-(x-i)]) ++cnt;
    }
    return cnt==x;
}
int bin(int lo, int hi) {
    int mid = (lo+hi)/2;
    if(num(mid)) {
        if(mid+1>hi || !num(mid+1)) return mid;
        return bin(mid+1, hi);
    }
    return bin(lo, mid-1);
}
int main() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+n);
    cout << bin(0, n);
}