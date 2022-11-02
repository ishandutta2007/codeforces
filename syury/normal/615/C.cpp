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
#include<list>
#include<map>
#include<utility>
#include<string>
#include<climits>

using namespace std;
typedef long long int lint;
typedef long double ldb;

const int inf = 1e9;

struct node {
    int len;
    map<char, node * > next;
    int fpos;
    node * link;
};

node * root;
node * last;

void sa_init(){
    root = new node;
    root->len = 0;
    root->link = NULL;
    root->fpos = -1;
    last = root;
}

void sa_extend(char c){
    node * curr = new node;
    curr->len = last->len + 1;
    curr->fpos = curr->len - 1;
    node * p = last;
    for(; p != NULL && !(p->next.count(c)); p = p->link){
        p->next[c] = curr;
    }
    if(p == NULL){
        curr->link = root;
    }
    else{
        node * q = p->next[c];
        if(p->len + 1 == q->len){curr->link = q;}
        else{
            node * clone = new node;
            clone->next = q->next;
            clone->link = q->link;
            clone->fpos = q->fpos;
            clone->len = p->len + 1;
            for(; p != NULL && p->next[c] == q; p = p->link){
                p->next[c] = clone;
            }
            q->link = curr->link = clone;
        }
    }
    last = curr;
}

void sa_build(string s){
    sa_init();
    for(int i = 0; i < s.length(); i++){
        sa_extend(s[i]);
    }
}

string s, t;
int n, m;
string tmp;
vector<int> lpos;
vector<int> dp;
vector<int> p;

void restore(int v, int slen){
    if(v == n){return;}
    int nxt = p[v];
    int old = v;
    int u = p[v] - 1;
    node * curr = root;
    while(v <= u){
        curr = curr->next[t[v]];
        v++;
    }
    int rp = curr->fpos;
    int lp = rp - (nxt - old) + 1;
    //cout << l << " " << r << endl;
    if(rp < slen){
        cout << lp + 1 << " " << rp + 1 << endl;
    }
    else{
        lp -= slen; rp -= slen;
        lp--; rp--;
        cout << slen - lp << " " << slen - rp<< endl;
    }
    restore(nxt, slen);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    int m = s.length();
    tmp = s;
    reverse(tmp.begin(), tmp.end());
    s = s + '+' + tmp;
    sa_build(s);
    //cout << "cde" << endl;
    n = t.length();
    lpos.resize(n);
    for(int i = 0; i < n; i++){
        node * curr = root;
        int j = i;
        while(j < n && curr->next.count(t[j])){
            curr = curr->next[t[j]];
            j++;
        }
        lpos[i] = j - 1;
    }
    //cout << "ajdf" << endl;
    dp.resize(n + 1);
    dp.assign(n + 1, inf);
    p.resize(n);
    p.assign(n, n);
    dp[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        int l = i, r = lpos[i];
        if(l > r){continue;}
        for(int j = l; j <= r; j++){
            if(dp[j + 1] + 1 < dp[i]){dp[i] = dp[j + 1] + 1; p[i] = j + 1;}
        }
    }
    if(dp[0] == inf){cout << "-1" << endl; return 0;}
    cout << dp[0] << endl;
    restore(0, m);
    return 0;
}