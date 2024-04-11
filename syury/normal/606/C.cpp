#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<utility>
#include<map>
#include<cstdlib>
#include<ctime>
#include<random>
#include<string>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long int lint;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<lint> vl;
typedef pair<int, int> pi;
typedef pair<lint, lint> pl;

int n;
vi a;
int ans = 1e9;
vi b;
vi c, s, nz;
int bseq = 0, eseq = 0;

int main(){
    scanf("%d", &n);
    a.resize(n); s.resize(n + 1); a.assign(n + 1, 0); s.assign(n, 0); c.resize(n); nz.resize(n);
    for(int i = 0; i < n; i++){scanf("%d", &a[i]);}
    int bseq = a[0];
    int curr = 1;
    while(curr < n && a[curr] == bseq + curr){curr++;}
    eseq = bseq + curr - 1;
    for(int i = n - 1; i >= 0; i--){
        s[a[i]] = 1;
        if(a[i] < n){
            c[a[i]] = s[a[i] + 1];
        }
    }
    for(int i = n - 1; i > 0; i--){
        if(i == n - 1){nz[i] = (c[i] == 1) ? n : n - 1;}
        else{
            nz[i] = (c[i] == 1) ? nz[i + 1] : i;
        }
    }
    for(int i = 0; i <= n; i++){
        int ccnt = 0;
        if(bseq <= i && eseq >= i){ccnt = bseq - 1;}
        else{ccnt += i;}
        int q = i + 1;
        if(q < n){
            int l = nz[q];
            ccnt += n - l;
        }
        //printf("%d\n", ccnt);
        ans = min(ans, ccnt);
    }
    printf("%d", ans);
    return 0;
}