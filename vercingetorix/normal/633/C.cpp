#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

struct vertex {
    vi next = vi(26, -1);
    int leaf = -1;
};

vector<vertex> t(1000001);
int sz;

void add_string (const string & s, int ind) {
    int v = 0;
//cout<<s<<endl;
    for (size_t i=0; i<s.length(); ++i) {
        int c = s[i]-'a'; //    

        if (t[v].next[c] == -1) {
 
            t[v].next[c] = sz;
sz++;
        }
        v = t[v].next[c];
    }
    t[v].leaf = ind;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif


    for(int i = 0; i<1000001; i++) t[i].leaf = -1;

    sz = 1;
    int  n,m;
     //int ans = 0;
    string s;
    scanf("%d\n", &n);
    getline(cin, s);
    scanf("%d\n", &m);
    vector<string> word(m);
    for(int i = 0; i<m; i++) getline(cin, word[i]);
    vector<string> word2 = word;
    for(auto & x : word2) {
        transform(x.begin(), x.end(), x.begin(), ::tolower);
    }

    for(int i = 0; i<m; i++) {
        add_string(word2[i], i);
    }


    vi down(n, -2);

    for(int i = 0; i<n; i++) {
        int curpos = i;
        int v = 0;
        while ((curpos>=0) && (v>=0)) {
            v=t[v].next[s[curpos]-'a'];
if(v==-1) break;
            curpos--;
            if ((t[v].leaf >= 0) && ((curpos<0)||(down[curpos] >= 0))) {
                down[i] = t[v].leaf;
                break;
            }
        }
    }
//for(auto x:down) cout<<x<<endl;
    deque<string> ans;
    int cur = n-1;

    while (cur >= 0) {
//cout<<cur<<" "<<down[cur]<<" "<<word[down[cur]]<<endl;
        ans.push_front(word[down[cur]]);
        cur-=word[down[cur]].size();
    }

    for(auto x: ans) printf("%s ", x.c_str());
    //cout<<ans;
}