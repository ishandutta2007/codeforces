#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<map>
#include<utility>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
typedef long long int lint;
typedef long double ldb;

const lint INF = 1e16;

const int MAXN = 1000005;

int cnt[MAXN];
int a[MAXN];
int n, k;

int can(int len){
    memset(cnt, 0, MAXN * sizeof(int));
    int curr = 0;
    for(int i = 0; i < len; i++){
        if(cnt[a[i]] == 0){curr++;}
        cnt[a[i]]++;
    }
    if(curr <= k){return 0;}
    for(int i = 1; i + len - 1 < n; i++){
        cnt[a[i - 1]]--;
        if(cnt[a[i - 1]] == 0){curr--;}
        if(cnt[a[i + len - 1]] == 0){curr++;}
        cnt[a[i + len - 1]]++;
        if(curr <= k){return i;}
    }
    return -1;
}

int binsearch(){
    int l = 1, r = n;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(can(mid) != -1){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    if(can(r) != -1){return r;}
    return l;
}

int main() {
    memset(cnt, 0, MAXN * sizeof(int));
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){scanf("%d", &a[i]);}
    int len = binsearch();
    int l = can(len);
    printf("%d %d", l + 1, l + len);
	return 0;
}