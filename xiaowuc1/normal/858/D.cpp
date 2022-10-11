#include <iostream>
#include <memory>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;

struct node {
    int cnt;
    node* child[10];
};

node* makeNode() {
    node* ret = new node;
    ret->cnt = 0;
    for(int i = 0; i < 10; i++) {
        ret->child[i] = NULL;
    }
    return ret;
}

node* root;

void addWord(string s) {
    node* curr = root;
    for(int i = 0; i < s.length(); i++) {
        if(curr->child[s[i]-'0'] == NULL) {
            curr->child[s[i]-'0'] = makeNode();
        }
        curr = curr->child[s[i]-'0'];
    }
    curr->cnt++;
}

bool valid(string s) {
    node* curr = root;
    for(int i = 0; i < s.length(); i++) {
        if(curr->child[s[i]-'0'] == NULL) {
            curr->child[s[i]-'0'] = makeNode();
        }
        curr = curr->child[s[i]-'0'];
    }
    return curr->cnt == 1;
}

char buf[70000][15];
int main() {
    int n;
    root = makeNode();
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", buf[i]);
        string ss = string(buf[i]);
        set<string> sss;
        for(int i = 0; i < ss.length(); i++) {
            for(int len = 1; len + i <= ss.length(); len++) {
                sss.insert(ss.substr(i, len));
            }
        }
        for(string ssss: sss) {
            addWord(ssss);
        }
    }
    for(int i = 0; i < n; i++) {
        string orig = string(buf[i]);
        bool done = false;
        for(int len = 1; len <= 10 && !done; len++) {
            for(int a = 0; a + len <= 10 && !done; a++) {
                string cand = orig.substr(a, len);
                if(valid(cand)) {
                    done = true;
                    for(int b = 0; b < len; b++) {
                        printf("%c", buf[i][a+b]);
                    }
                    printf("\n");
                }
            }
        }
    }
}