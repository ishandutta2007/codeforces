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
#include <list>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

list <char> lst;
list <char>::iterator it1, it2, it_tmp;

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s;
    int n, i, f;
    cin >> s;
    n = s.length();
    for(i = 0; i < n; i++){
        lst.push_back(s[i]);
    }
    it1 = lst.begin();
    it2 = it1;
    for(; it2 != lst.end(); ){
        if (it1 == it2){
            it2++;
            continue;
        }
        if ((*it1) == (*it2)){
            it_tmp = it1;
            f = 0;
            if (it1 == lst.begin()){
                f = 1;
            }
            else{
                it1--;
            }   
            lst.erase(it_tmp);
            it_tmp = it2;
            it2++;
            lst.erase(it_tmp);
            if (f){
                it1 = lst.begin();
            }
        }
        else{
            it1++;
            it2++;
        }
    }
    for(it1 = lst.begin(); it1 != lst.end(); it1++){
        putchar(*it1);
    }
}