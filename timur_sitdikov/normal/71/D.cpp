#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

set <string> used;

int n, m, i1, j11, i2, j2;
string s[50][50];

int check(int a, int b){
    int i, j;
    set<char> sym1, sym2;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            sym1.insert(s[a + i][b + j][0]);
            sym2.insert(s[a + i][b + j][1]);
        }
    }
    if (sym1.size() == 9 || sym2.size() == 0)
        return 1;
    return 0;
}

int gen_check(){
    for(i1 = 0; i1 < n - 2; i1++){
        for(j11 = 0; j11 < m - 2; j11++){
            if (!check(i1, j11))
                continue;
            for(i2 = i1; i2 < min(n - 2, i1 + 3); i2++){
                for(j2 = 0; j2 < j11 - 2; j2++){
                    if (check(i2, j2))
                        return 1;
                }
                for(j2 = j11 + 3; j2 < m - 2; j2++){
                    if (check(i2, j2))
                        return 1;
                }
            }
            for(i2 = i1 + 3; i2 < n - 2; i2++){
                for(j2 = 0; j2 < m - 2; j2++){
                    if (check(i2, j2))
                        return 1;
                }
            }
        }
    }
    return 0;
}

string c1[15], c2[15];

void init(){
    c2[0] = "C";
    c2[1] = "D";
    c2[2] = "H";
    c2[3] = "S";

    c1[0] = "2";
    c1[1] = "3";
    c1[2] = "4";
    c1[3] = "5";
    c1[4] = "6";
    c1[5] = "7";
    c1[6] = "8";
    c1[7] = "9";
    c1[8] = "T";
    c1[9] = "J";
    c1[10] = "Q";
    c1[11] = "K";
    c1[12] = "A";   
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, ii, jj, f, a1, b1, a2, b2;
    string ss, sss;
    init();
    cin >> n >> m;
    f = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> s[i][j];
            if (s[i][j] == "J1" || s[i][j] == "J2")
                f++;
            else
                used.insert(s[i][j]);;
        }
    }
    if (!f){
        if (gen_check()){
            printf("Solution exists.\n");
            printf("There are no jokers.\n");
            printf("Put the first square to (%d, %d).\n", i1 + 1, j11 + 1);
            printf("Put the second square to (%d, %d).\n", i2 + 1, j2 + 1);
            return 0;
        }
        printf("No solution.");
        return 0;
    }
    if (f == 1){
        int f1 = 2;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if (s[i][j] == "J1" || s[i][j] == "J2"){
                    a1 = i;
                    b1 = j;
                    if (s[i][j] == "J1")
                        f1 = 1;
                }
            }
        }
        for(i = 0; i < 13; i++){
            for(j = 0; j < 4; j++){
                ss = c1[i] + c2[j];
                if (used.find(ss) != used.end())
                    continue;
                s[a1][b1] = ss;
                if (gen_check()){
                    printf("Solution exists.\n");
                    printf("Replace J%d with %c%c.\n", f1, ss[0], ss[1]);
                    printf("Put the first square to (%d, %d).\n", i1 + 1, j11 + 1);
                    printf("Put the second square to (%d, %d).\n", i2 + 1, j2 + 1);
                    return 0;
                }
                
            }
        }
        printf("No solution.");
        return 0;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if (s[i][j] == "J1"){
                a1 = i;
                b1 = j;
            }
            if (s[i][j] == "J2"){
                a2 = i;
                b2 = j;
            }
        }
    }
    for(i = 0; i < 13; i++){
        for(j = 0; j < 4; j++){
            ss = c1[i] + c2[j];
            if (used.find(ss) != used.end())
                continue;
            s[a1][b1] = ss;
            for(ii = 0; ii < 13; ii++){
                for(jj = 0; jj < 4; jj++){
                    sss = c1[ii] + c2[jj];
                    if (used.find(sss) != used.end())
                        continue;
                    s[a2][b2] = sss;
                    if (i == ii && j == jj)
                        continue;
                    if (used.find(sss) != used.end())
                        continue;
                    if (gen_check()){
                        printf("Solution exists.\n");
                        printf("Replace J1 with %c%c and J2 with %c%c.\n", ss[0], ss[1], sss[0], sss[1]);
                        printf("Put the first square to (%d, %d).\n", i1 + 1, j11 + 1);
                        printf("Put the second square to (%d, %d).\n", i2 + 1, j2 + 1);
                        return 0;
                    }
                }
            }       
        }
    }
    printf("No solution.");
    return 0;
}