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
#define xx first
#define yy second

long long mod = 1 << 14;

long long get_hash(long long a, long long b, long long c, long long d){
    return d + mod * (c + mod * (b + mod * a));
}

set<long long> st[2];
set<long long>::iterator it;

set<string> ans;
set<string>::iterator its;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    int n, i, ind;
    long long v, a, b, c, d, a1, b1, c1, d1;
    cin >> n >> s;
    st[0].insert(0);
    for(i = 0; i < n; i++){
        a1 = b1 = c1 = d1 = 0;
        ind = i & 1;
        st[ind ^ 1].clear();
        if (s[i] == '?'){
            for(it = st[ind].begin(); it != st[ind].end(); it++){
                a = b = c = d = 0;
                v = *it;
                d += v % mod;
                v /= mod;
                c += v % mod;
                v /= mod;
                b += v % mod;
                v /= mod;
                a += v % mod;
                v = a;
                v = min(v, b);
                v = min(v, c);
                v = min(v, d);
                if (v == a)
                    st[ind ^ 1].insert(get_hash(a + 1, b, c, d));
                if (v == b)
                    st[ind ^ 1].insert(get_hash(a, b + 1, c, d));
                if (v == c)
                    st[ind ^ 1].insert(get_hash(a, b, c + 1, d));
                if (v == d)
                    st[ind ^ 1].insert(get_hash(a, b, c, d + 1));
            }
            continue;
        }
        if (s[i] == 'G'){
            a1 = 1;
        }
        if (s[i] == 'H'){
            b1 = 1;
        }
        if (s[i] == 'R'){
            c1 = 1;
        }
        if (s[i] == 'S'){
            d1 = 1;
        }
        for(it = st[ind].begin(); it != st[ind].end(); it++){
            a = b = c = d = 0;
            v = *it;
            d += v % mod;
            v /= mod;
            c += v % mod;
            v /= mod;
            b += v % mod;
            v /= mod;
            a += v % mod;
            st[ind ^ 1].insert(get_hash(a + a1, b + b1, c + c1, d + d1));
        }
    }
    for(it = st[n & 1].begin(); it != st[n & 1].end(); it++){
        a = b = c = d = 0;
        v = *it;
        d += v % mod;
        v /= mod;
        c += v % mod;
        v /= mod;
        b += v % mod;
        v /= mod;
        a += v % mod;
        v = a;
        v = min(v, b);
        v = min(v, c);
        v = min(v, d);
        if (v == a)
            ans.insert("Gryffindor");
        if (v == b)
            ans.insert("Hufflepuff");
        if (v == c)
            ans.insert("Ravenclaw");
        if (v == d)
            ans.insert("Slytherin");
    }
    for(its = ans.begin(); its != ans.end(); its++)
        cout << (*its) << endl;
}