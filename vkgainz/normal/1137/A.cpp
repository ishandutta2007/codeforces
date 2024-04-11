#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;

int main() {
    int n,m; cin >> n >> m;
    int a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    pair<int, int> x[n][m];
    pair<int, int> y[n][m];
    for(int i=0;i<n;i++) {
        set<int> s;
        for(int j=0;j<m;j++) {
            x[i][j] = {0,0};
            s.insert(a[i][j]);
        }
        map<int, int> di;
        int v = 1;
        for(auto &it : s) di[it] = v++;
        for(int j=0;j<m;j++) {
            x[i][j].f = di[a[i][j]];
            x[i][j].s = v-di[a[i][j]];
        }
    }
    for(int j=0;j<m;j++) {
        set<int> s;
        for(int i=0;i<n;i++) {
            y[i][j] = {0, 0};
            s.insert(a[i][j]);
        }
        map<int, int> di;
        int v=  1;
        for(auto &it : s) di[it] = v++;
        for(int i=0;i<n;i++) {
            y[i][j].f = di[a[i][j]];
            y[i][j].s = v-di[a[i][j]];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%d ",max(x[i][j].f, y[i][j].f)+max(x[i][j].s, y[i][j].s)-1);
        }
        printf("\n");
    }
}