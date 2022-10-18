#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

pair <int, int> st[101];
bool jud[101];
int n;

void dfs(int k){
    for (int i = 0; i < n; i++){
        if (!jud[i] && (st[i].fi == st[k].fi || st[i].se == st[k].se)){
            jud[i] = 1;
            dfs(i);
        }
    }
}

int main(){
    int k;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> st[i].fi >> st[i].se;
    }
    memset(jud, 0, sizeof(jud));
    k = 0;
    for (int i = 0; i < n; i++){
        if (!jud[i]){
            k++;
            jud[i] = 1;
            dfs(i);
        }
    }
    cout << k - 1;
}