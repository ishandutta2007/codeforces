#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    int maxE = a[n-1];
    int maxSE = a[n-2];
    int cycleLen = k+1;
    ll tot = (ll) k*maxE+maxSE;
    int numCycle = m/cycleLen;
    tot*=numCycle;
    tot+=(ll) (m%cycleLen)*maxE;
    cout << tot << endl;
}