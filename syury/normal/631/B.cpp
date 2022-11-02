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

vector<int> lastc, lastr, tc, tr;
int n, m, q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d%d", &n, &m, &q);
    lastr.resize(n); lastc.resize(m);
    lastr.assign(n, 0); lastc.assign(m, 0);
    tr.resize(n); tc.resize(m);
    tr.assign(n, 0); tc.assign(m, 0);
    for(int i = 1; i <= q; i++){
        int tp, pos, col;
        scanf("%d%d%d", &tp, &pos, &col);
        pos--;
        if(tp == 1){
            tr[pos] = i; lastr[pos] = col;
        }
        else{
            tc[pos] = i; lastc[pos] = col;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tc[j] > tr[i]){
                printf("%d ", lastc[j]);
            }
            else{
                printf("%d ", lastr[i]);
            }
        }
        printf("\n");
    }
    return 0;
}