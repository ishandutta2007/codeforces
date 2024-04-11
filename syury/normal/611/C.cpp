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
#include<climits>

using namespace std;
typedef long long int lint;
typedef long double ldb;

lint h, w, q;
vector<vector<char> > field;
vector<vector<int> > sumh, sumv;

char myget(){
    char tmp = ';';
    while(tmp != '.' && tmp != '#'){
        tmp = getc(stdin);
    }
    return tmp;
}

int geth(int x1, int y1, int x2, int y2){
    if(x1 > x2 || y1 > y1){
        return 0;
    }
    if(x1 == 0 && y1 == 0){return sumh[x2][y2];}
    if(x1 == 0){return sumh[x2][y2] - sumh[x2][y1 - 1];}
    if(y1 == 0){return sumh[x2][y2] - sumh[x1 - 1][y2];}
    return sumh[x2][y2] - sumh[x1 - 1][y2] - sumh[x2][y1 - 1] + sumh[x1 - 1][y1 - 1];
}

int getv(int x1, int y1, int x2, int y2){
    if(x1 > x2 || y1 > y1){
        return 0;
    }
    if(x1 == 0 && y1 == 0){return sumv[x2][y2];}
    if(x1 == 0){return sumv[x2][y2] - sumv[x2][y1 - 1];}
    if(y1 == 0){return sumv[x2][y2] - sumv[x1 - 1][y2];}
    return sumv[x2][y2] - sumv[x1 - 1][y2] - sumv[x2][y1 - 1] + sumv[x1 - 1][y1 - 1];
}

int main(){
    scanf("%d%d", &h, &w);
    field.resize(h);
    sumh.resize(h); sumv.resize(h);
    for(int i = 0; i < h; i++){
        field[i].resize(w); sumh[i].resize(w); sumv[i].resize(w);
        for(int j = 0; j < w; j++){
            field[i][j] = myget();
            int dv = 0, dh = 0;
            if(field[i][j] == '.' && j > 0 && field[i][j - 1] == '.'){dh = 1;}
            if(field[i][j] == '.' && i > 0 && field[i - 1][j] == '.'){dv = 1;}
            sumh[i][j] = 0; sumv[i][j] = 0;
            if(i > 0){sumh[i][j] += sumh[i - 1][j]; sumv[i][j] += sumv[i - 1][j];}
            if(j > 0){sumh[i][j] += sumh[i][j - 1]; sumv[i][j] += sumv[i][j - 1];}
            if(i > 0 && j > 0){sumh[i][j] -= sumh[i - 1][j - 1]; sumv[i][j] -= sumv[i - 1][j - 1];}
            sumh[i][j] += dh; sumv[i][j] += dv;
        }
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1--; y1--; x2--; y2--;
        printf("%d\n", geth(x1, y1 + 1, x2, y2) + getv(x1 + 1, y1, x2, y2));
    }
    return 0;
}