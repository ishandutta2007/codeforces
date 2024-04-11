#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

void output(string &s){
    putchar('<');
    cout << s;
    putchar('>');
    putchar('\n');
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char c;
    string ans;
    int fl = 0;
    for(; c = getchar(), c != '\n' && c != EOF; ){
        if (fl){
            if (c == '"'){
                output(ans);
                ans.clear();
                fl = 0;
            }
            else{
                ans.pb(c);
            }
        }
        else{
            if (c == '"'){
                fl = 1;
                continue;
            }
            if (c == ' '){
                if (!ans.empty()){
                    output(ans);
                    ans.clear();
                }
            }
            else{
                ans.pb(c);
            }
        }
    }
    if (!ans.empty()){
        output(ans);
    }
}