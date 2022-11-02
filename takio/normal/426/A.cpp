#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n,s,sum = 0,a;
    cin >> n >> s;
    int mx = -1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        sum += a;
        mx = max(mx, a);
    }
//    cout<<sum - mx;
    if(sum - mx <= s) cout << "YES";
        else cout << "NO";
}