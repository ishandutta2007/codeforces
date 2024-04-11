#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<set>
#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<cassert>
#include<ctime>

#define X first
#define Y second

using namespace std;
typedef long long lint;

int a[2001], b[2001];
int n;
lint ans = 0ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int j = 0; j < n; j++)
        scanf("%d", &b[j]);
    for(int i = 0; i < n; i++){
        lint curra = 0ll, currb = 0ll;
        for(int j = i; j < n; j++){
            lint v = (lint)a[j], u = (lint)b[j];
            curra |= v; currb |= u;
            ans = max(ans, curra + currb);
        }
    }
    cout << ans << endl;
    return 0;
}