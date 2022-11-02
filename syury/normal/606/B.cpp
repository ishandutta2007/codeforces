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

int n, m, k;
vector<vector<char> > f;
int x, y;
int cnt;
string s;
vi nums;

int getdy(char c){
    if(c == 'L'){return -1;}
    if(c == 'R'){return 1;}
    return 0;
}

int getdx(char c){
    if(c == 'U'){return -1;}
    if(c == 'D'){return 1;}
    return 0;
}

int main(){
    scanf("%d%d%d%d\n", &n, &m, &x, &y); x--; y--;
    f.resize(n);
    for(int i = 0; i < n; i++){
        f[i].resize(m); f[i].assign(m, false);
    }
    cin >> s;
    int l = s.length();
    nums.resize(l + 1);
    cnt = n * m - 1;
    nums[0] = n * m;
    f[x][y] = true;
    for(int i = 0; i < l; i++){
        nums[i + 1] = cnt;
        x = x + getdx(s[i]);
        y = y + getdy(s[i]);
        if(x < 0){++x;}
        if(x> n - 1){--x;}
        if(y < 0){++y;}
        if(y > m -1){--y;}
        if(!f[x][y]){cnt--; f[x][y] = true;}
    }
    for(int i = 0; i <= l; i++){
        printf("%d ", (i < l) ? nums[i] - nums[i + 1] : nums[i]);
    }
    return 0;
}