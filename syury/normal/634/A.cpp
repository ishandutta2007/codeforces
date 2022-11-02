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

typedef long long int lint;
typedef long double ldb;

vector<int> a, b, c, d;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &n);
    a.resize(n); b.resize(n);
    int fp, sp;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] == 0)
            fp = i;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
        if(b[i] == 0)
            sp = i;
    }
    bool easy_ans = true;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i])
            easy_ans = false;
    }
    if(easy_ans){
        printf("YES");
        return 0;
    }
    while(fp != sp){
        int prv = (fp == 0) ? (n - 1) : (fp - 1);
        swap(a[fp], a[prv]);
        fp = prv;
    }
    a.erase(find(a.begin(), a.end(), 0));
    b.erase(find(b.begin(), b.end(), 0));
    c.resize(n - 1); d.resize(n - 1);
    for(int i = 0; i < n - 1; i++){
        c[i] = d[i] = a[i];
    }
    int pc, pd;
    for(int i = 0; i < n - 1; i++){
        if(a[i] == b[0]){
            pc = pd = i;
            break;
        }
    }
    int cpos = pc, bp = 0;
    bool ft = true;
    bool ok = true;
    while(cpos != pc || ft){
        ft = false;
        if(c[cpos] != b[bp]){
            ok = false; break;
        }
        cpos = (cpos == n - 2) ? 0 : (cpos + 1);
        bp++;
    }

    if(ok){
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
}