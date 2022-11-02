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

vector<vector<char> > f;
int csz[MAXN];
int sz = 0;
vector<vector<char> > used;
vector<vector<int> > vid;
int n, m;

char myget(){
    char c = '!';
    while(c != '*' && c != '.')
        c = getc(stdin);
    return c;
}

void dfs(int i, int j, int id){
    vid[i][j] = id;
    csz[id]++;
    used[i][j] = true;
    if(i > 0 && f[i - 1][j] == '.' && !used[i - 1][j])
        dfs(i - 1, j, id);
    if(j > 0 && f[i][j - 1] == '.' && !used[i][j - 1])
        dfs(i, j - 1, id);
    if(i < n - 1 && f[i + 1][j] == '.' && !used[i + 1][j])
        dfs(i + 1, j, id);
    if(j < m - 1 && f[i][j + 1] == '.' && !used[i][j + 1])
        dfs(i, j + 1, id);
}

int main() {
    memset(csz, 0, MAXN * sizeof(int));
    scanf("%d%d", &n, &m);
    f.resize(n); used.resize(n); vid.resize(n);
    for(int i = 0; i < n; i++){
        f[i].resize(m); used[i].resize(m); vid[i].resize(m);
        used[i].assign(m, false);
        for(int j = 0; j < m; j++){
            f[i][j] = myget();
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(f[i][j] == '*' || used[i][j]){continue;}
            dfs(i, j, sz++);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(f[i][j] == '.'){printf("."); continue;}
            set<int> ids;
            int curr = 1;
            if(i > 0 && f[i - 1][j] == '.')
                ids.insert(vid[i - 1][j]);
               if(j > 0 && f[i][j - 1] == '.')
                ids.insert(vid[i][j - 1]);
                   if(j < m - 1 && f[i][j + 1] == '.')
                ids.insert(vid[i][j + 1]);
                   if(i < n - 1 && f[i + 1][j] == '.')
                ids.insert(vid[i + 1][j]);
            for(auto it = ids.begin(); it != ids.end(); it++){
                curr += csz[*it];
            }
            printf("%d", curr%10);
        }
        printf("\n");
    }
	return 0;
}