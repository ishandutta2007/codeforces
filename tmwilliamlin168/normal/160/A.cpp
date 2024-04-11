#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, sum=0, csum=0, num=0;
    cin >> n;
    int* ar = new int[n];
    for(int i=0; i<n; ++i) {
    	cin >> ar[i];
    	sum+=ar[i];
    }
    sort(ar, ar+n);
    while(csum*2<=sum) {
    	++num;
    	csum+=ar[n-num];
    }
    cout << num;
    return 0;
}