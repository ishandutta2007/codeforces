#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<set>
#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<cassert>
#include<ctime>

#define X first
#define Y second

using namespace std;
typedef long long lint;

bool gcmp(const int & i, const int & j){
    return i > j;
}

int n, m;
vector<int> a;
vector<pair<int, int> > r;
vector<pair<int, int> > mx;
list<pair<int, int> > ml;
list<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d", &n, &m);
    a.resize(n); r.resize(m); mx.resize(m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &r[i].X, &r[i].Y);
    }
    for(int i = m - 1; i >= 0; i--){
        if(i == m - 1 || r[i].Y >= mx[i + 1].X){
            mx[i] = make_pair(r[i].Y, i);
        }
        else{
            mx[i] = mx[i + 1];
        }
    }
    int ptr = 0;
    while(ptr < m){
        if(mx[ptr].Y != ptr){
            ptr = mx[ptr].Y;
            continue;
        }
        ml.push_back(r[ptr]);
        ptr++;
    }
    int scnt = ml.begin()->second;
    if(ml.begin()->first == 1){
        sort(a.begin(), a.begin() + scnt);
    }
    else{
        sort(a.begin(), a.begin() + scnt, gcmp);
    }
    for(int i = scnt; i < n; i++){
        ans.push_back(a[i]);
    }
    int l = 0, r = scnt - 1;
    bool rev = false;
    auto it = ml.begin();
    int prc = it->first;
    it++;
    while(it != ml.end()){
        scnt = it->second;
        int bpos = (rev) ? (l) : (r);
        for(int i = bpos; i != ((rev) ? (r - scnt + 1) : (l + scnt - 1)); i += ((rev) ? (1) : (-1))){
            ans.push_front(a[i]);
        }
        int nl, nr;
        if(rev){
            nr = r; nl = r - scnt + 1;
        }
        else{
            nl = l; nr = l + scnt - 1;
        }
        l = nl; r = nr;
        if(it->first != prc)
            rev = !rev;
        prc = it->first;
        it++;
    }
    if(rev){
        while(l <= r){
            ans.push_front(a[l]); l++;
        }
    }
    else{
        while(r >= l){
            ans.push_front(a[r]); r--;
        }
    }
    for(auto ait = ans.begin(); ait != ans.end(); ait++)
        printf("%d ", (*ait));
    return 0;
}