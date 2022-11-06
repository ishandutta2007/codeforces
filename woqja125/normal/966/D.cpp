#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
using namespace std;
int d[300001], p[300001];
vector<int> map[300001];
int n;
void printSimple(int n){
    printf("%d\n", d[n]);
    vector<int> ans;
    while(n != 1){
        ans.push_back(n);
        n = p[n];
    }
    printf("1 ");
    for(int i=ans.size()-1; i>=0; i--) printf("%d ", ans[i]);
    printf("\n");
}

void print5(int a, int b, int c){ // 1-a,1-b,1-c,a-c,b-c on; a-b off
    printf("5\n1 %d %d %d %d %d\n", b, c, a, b, n);
    exit(0);
}

void cmp(int a, int b){
    // 1-a, 1-b, a-b; 
    map[b].push_back(b);
    map[b].push_back(n+1);
    sort(map[b].begin(), map[b].end());
    for(int i=0; i<map[a].size() && i<map[b].size(); i++){
        if(map[a][i] != map[b][i]){
            if(map[a][i] < map[b][i]) print5(b, map[a][i], a);
            else print5(a, map[b][i], b);
        }
    }
}

void find5(int x){
    d[x] = -1;
    map[x].push_back(x);
    map[x].push_back(n+1);
    sort(map[x].begin(), map[x].end());
    for(auto e: map[x]){
        if(e==1 || e==x || e==n+1) continue;
        cmp(x, e);
        d[e] = -1;
    }
}

int main(){
    int m, x, y;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++){
        scanf("%d%d", &x, &y);
        map[x].push_back(y);
        map[y].push_back(x);
    }
    for(int i=1; i<=n; i++) d[i] = 100000000;
    d[1] = 0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int x = Q.front(); Q.pop();
        for(auto e: map[x]){
            if(d[e] > d[x] + 1){
                d[e] = d[x] + 1;
                p[e] = x;
                Q.push(e);
            }
        }
    }
    if(d[n] <= 4){
        printSimple(n);
        return 0;
    }
    for(int i=1; i<=n; i++){
        if(d[i] == 2){
            printf("4\n1 %d %d 1 %d\n", p[i], i, n);
            return 0;
        }
    }
    // find 5
    for(int i=2; i<=n; i++){
        if(d[i] == 1){
            find5(i);
        }
    }
    if(d[n] != 100000000){
        printSimple(n);
        return 0;
    }
    printf("-1\n");
    return 0;
}