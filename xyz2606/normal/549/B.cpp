#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;
const int N(111);
int deg[N], exp[N];;
char a[N][N];
bool ext[N];
int main() {
    int n;
    scanf("%d", &n);
    for(int i(0); i < n; i++) {
        scanf("%s", a[i]);
        for(int j(0); j < n; j++) {
            deg[j] += a[i][j] == '1';
        }
        ext[i] = true;
    }
    for(int i(0); i < n; i++) {
        scanf("%d", &exp[i]);
    }
    bool flag(true);
    while(flag) {
        flag = false;
        int I;
        for(int i(0); i < n; i++) {
            if(exp[i] == deg[i]) {
                flag = true;
                I = i;
                break;
            }
        }
        if(!flag) {
            break;
        }
        ext[I] = false;
        for(int i(0); i < n; i++) {
            deg[i] -= a[I][i] == '1';
        }
    }
    vector<int> ans;
    for(int i(0); i < n; i++) {
        if(ext[i]) {
            ans.push_back(i + 1);
        }
    }
    printf("%d\n", ans.size());
    for(int i(0); i < (int)ans.size(); i++) {
        printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
    }
}