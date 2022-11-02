#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
#include<stack>

#define X first
#define Y second

using namespace std;
typedef long long int lint;
typedef long double ldb;


int k;
int is[31];
int maxw = 0;
int num;

vector<string> ans;

int main(){
    scanf("%d", &k);
    if(k == 1){
        printf("2\nNY\nYN");
        return 0;
    }
    memset(is, 0, 31 * sizeof(int));
    for(int i = 0; i <= 30; i++)
        if(k & (1 << i)){
            is[i] = 1;
            maxw = i;
        }
    num = 3 * maxw + 2;
    ans.resize(num);
    for(int i = 0; i < num; i++){
        ans[i] = string(num, 'N');
    }
    ans[0][2] = 'Y'; ans[2][0] = 'Y'; ans[0][3] = 'Y'; ans[3][0] = 'Y';
    for(int level = 1; level <= maxw; level++){
        int l = 1 + 2 * level;
        int r = l + 1;
        if(level == maxw){
            ans[l - 1][1] = 'Y';
            ans[1][l - 1] = 'Y';
            ans[r - 1][1] = 'Y';
            ans[1][r - 1] = 'Y';
        }
        else{
            int nl = l + 2, nr = r + 2;
            ans[l - 1][nl - 1] = ans[nl - 1][l - 1] = 'Y';
            ans[l - 1][nr - 1] = ans[nr - 1][l - 1] = 'Y';
            ans[r - 1][nl - 1] = ans[nl - 1][r - 1] = 'Y';
            ans[r - 1][nr - 1] = ans[nr - 1][r - 1] = 'Y';
        }
    }
    int f = 2 + 2 * (maxw);
    for(int i = 0; i < maxw; i++){
        if(i == maxw - 1){
            ans[f + i][1] = ans[1][f + i] = 'Y';
        }
        else{
            ans[f + i][f + i + 1] = ans[f + i + 1][f + i] = 'Y';
        }
    }
    for(int i = 0; i < maxw; i++){
        if(!is[i])
            continue;
        if(i == 0){
            ans[0][f] = ans[f][0] = 'Y';
        }
        else{
            int l = 1 + 2 * i;
            int r = l + 1;
            ans[l - 1][f + i] = ans[f + i][l - 1] = 'Y';
            ans[r - 1][f + i] = ans[f + i][r - 1] = 'Y';
        }
    }
    printf("%d\n", num);
    for(int i = 0; i < num; i++){
        printf("%s\n", ans[i].c_str());
    }
    return 0;
}