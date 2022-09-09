#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
int arr[300100];
int loc[300100];

vector<pii> vec;
void sw(int a, int b) {
    swap(loc[arr[a]],loc[arr[b]]);
    swap(arr[a],arr[b]);
}

void Do(int v) {
    if (v<n/2) {
        if (loc[v]>=n/2) {
            vec.push_back({loc[v],0});
            sw(loc[v],0);
            vec.push_back({0,n-1});
            sw(0,n-1);
        }
        else {
            vec.push_back({loc[v],n-1});
            sw(loc[v],n-1);
        }
        vec.push_back({v,n-1});
        sw(v,n-1);
    }
    else {
        if (loc[v]<n/2) {
            vec.push_back({loc[v],n-1});
            sw(loc[v],n-1);
            vec.push_back({0,n-1});
            sw(0,n-1);
        }
        else {
            vec.push_back({loc[v],0});
            sw(loc[v],0);
        }
        vec.push_back({v,0});
        sw(v,0);
    }
}

int main() {
    int i;
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]); arr[i]--;
        loc[arr[i]] = i;
    }
    for (i=0;i<n/2-1;i++) {
        Do(n/2-i-1);
        Do(n/2+i);
    }
    if (arr[0]!=0) {
        vec.push_back({0,n-1});
        sw(0,n-1);
    }
    printf("%d\n",vec.size());
    for (pii &v : vec) {
        printf("%d %d\n",v.x+1,v.y+1);
    }

    return 0;
}