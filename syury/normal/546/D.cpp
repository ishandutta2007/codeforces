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

const int MAX = 5000004;

int cnt[MAX];
int ccnt[MAX];
int ct[MAX];
int a, b;
int gt = 0;
int n;
lint sum[MAX];

int get(int pos){
    if(ct[pos] < gt){
        ct[pos] = gt;
        ccnt[pos] = 0;
        return 0;
    }
    return ccnt[pos];
}

lint getsum(int l, int r){
    if(l > r){return 0ll;}
    return (l == 0) ? sum[r] : (sum[r] - sum[l - 1]);
}

int main(){
    memset(cnt, 0, MAX * sizeof(int));
    memset(ct, 0, MAX * sizeof(int));
    //ios_base::sync_with_stdio(false);
    for(int i = 2; i < MAX; i++){
        if(cnt[i] == 0){
            gt++;
            int d = 0;
            for(int j = i; j < MAX; j += i){
                d++;
                cnt[j] += 1 + get(d);
                ct[j] = gt;
                ccnt[j] = 1 + get(d);
            }
        }
    }
    for(int i = 2; i < MAX; i++){
        sum[i] = (i == 2) ? cnt[i] : (sum[i - 1] + cnt[i]);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        printf("%I64d\n", getsum(b + 1, a));
    }
    return 0;
}