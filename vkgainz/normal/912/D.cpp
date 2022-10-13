#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
int n,m,r,k;
map<int,int,greater<int> > a,b;
map<long long, long long, greater<long long>> freq;
bool num(long long e) {
    long long numPairs = 0;
    for(auto &x : a) {
        for(auto &y : b) {
            if(x.f*1LL*y.f>=e) {
                numPairs+=x.s*1LL*y.s;
                if(numPairs>=k) return true;
            }
            else break;
        }
    }
    return numPairs>=k;
}
long long binarySearch(long long lo,long long hi) {
    long long mid = (lo+hi)/2;
    if(num(mid)) {
        if(!num(mid+1)) {
            return mid;
        }
        return binarySearch(mid+1,hi);
    }
    return binarySearch(lo,mid-1);
}
int main(){
    cin >> n >> m >> r >> k;
    int hi = min(r,n-r+1)-1;
    for(int i=0;i<hi;i++) ++a[i+1];
    for(int i=hi;i<n-hi;i++) ++a[hi+1];
    for(int i=n-hi;i<n;i++) ++a[n-i];
    hi = min(r,m-r+1)-1;
    for(int i=0;i<hi;i++) ++b[i+1];
    for(int i=hi;i<m-hi;i++) ++b[hi+1];
    for(int i=m-hi;i<m;i++) ++b[m-i];
    long long bar = binarySearch(0,n*1LL*m);
    for(auto &x : a) {
        for(auto &y : b) {
            if(x.f*1LL*y.f>=bar) {
                freq[x.f*1LL*y.f]+=x.s*1LL*y.s;
            }
            else break;
        }
    }
    auto it = freq.begin();
    long long ans = 0;
    while(k>0 && it!=freq.end()) {
        if((*it).s>=k) {
            ans+=(*it).f*1LL*k;
            k = 0;
        }
        else {
            ans+=(*it).f*1LL*(*it).s;
            k-=(*it).s;
        }
        ++it;
    }
    long long div = (n-r+1)*1LL*(m-r+1);
    double ret = ans*1.0/div;
    cout << setprecision(12);
    cout << ret << endl;
    
}