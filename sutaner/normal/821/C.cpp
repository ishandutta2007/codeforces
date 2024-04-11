#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include<vector>
#include<queue>
#define maxn 400005
using namespace std;

priority_queue< int,vector<int>,greater<int> > save;
int seem[maxn];
int cnt;
int goal = 1;
int sum;
char s[10];
int n;

int main(){
    /*freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);*/
    scanf("%d", &n);
    for (int i = 0; i < (n << 1); i++){
        scanf("%s", s);
        if (s[0] == 'r'){
            if ((!cnt) || (seem[cnt] != goal)){
                if (cnt) sum++;
                for (int i = 1; i <= cnt; i++){
                    save.push(seem[i]);
                }
                cnt = 0;
                save.pop();
            }
            else cnt--;
            goal++;
        }
        else{
            int op;
            scanf("%d", &op);
            seem[++cnt] = op;
        }
    }
    printf("%d" ,sum);
    return 0;
}