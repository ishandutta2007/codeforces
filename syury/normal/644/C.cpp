#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<utility>
#include<iostream>

#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define rs resize
#define asg assign
#define mk make_pair
#define all(x) x.begin(),x.end()
#define pb push_back
#define ret return
#define X first
#define Y second

using namespace std;
typedef long long lint;

struct node{
    set<int> is;
    map<int, node*> next;
};

int n;
string tmp;
string name, q;
map<string, int> grq, grn;
map<int, string> rv;
set<pair<int, int> > has;
vector<int> p, s;
int szn = 0, szq = 0;
set<int> was;
set<node*> ans;
node * root = new node;
map<int, node*> ptr;
vector<set<int> > vv;

void make_set(int v){
    p[v] = v; s[v] = 1;
}

int find_set(int v){
    return (v == p[v]) ? v : (p[v] = find_set(p[v]));
}

void unite_sets(int v, int u){
    v = find_set(v); u = find_set(u);
    if(v == u)
        ret;
    if(s[u] < s[v])
        swap(v, u);
    p[v] = u;
    s[u] += s[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    p.rs(n); s.rs(n); vv.rs(n);
    F(i, 0, n){
        cin >> tmp;
        tmp = tmp.substr(7);
        size_t pos = tmp.find_first_of('/');
        name = tmp.substr(0, pos);
        if(pos == string::npos)q = "";
        else q = tmp.substr(pos);
        if(!grn.count(name)){root->is.insert(szn); ptr[szn] = root; rv[szn] = name; grn[name] = szn++;}
        if(!grq.count(q)){grq[q] = szq++;}
        int cgn = grn[name], cgq = grq[q];
        if(has.find(mk(cgn, cgq)) != has.end())
            continue;
        has.insert(mk(cgn, cgq));
        vv[cgn].insert(cgq);
    }
    /*    if(!ptr[cgn]->next.count(cgq)){ptr[cgn]->next[cgq] = new node;}else{
            ptr[cgn]->is.erase(cgn);
            ptr[cgn] = ptr[cgn]->next[cgq];
            ptr[cgn]->is.insert(cgq);
        }
    }*/
    F(cgn, 0, szn){
        if(vv[cgn].empty())
            continue;
        F(it, vv[cgn].begin(), vv[cgn].end()){
            int cgq = *it;
        if(!ptr[cgn]->next.count(cgq)){ptr[cgn]->next[cgq] = new node;}
            ptr[cgn]->is.erase(cgn);
            ptr[cgn] = ptr[cgn]->next[cgq];
            ptr[cgn]->is.insert(cgn);

        }
    }
    F(it, grn.begin(), grn.end()){
        if(ptr[it->Y]->is.size() < 2)
            continue;
        ans.insert(ptr[it->Y]);
    }
    cout << ans.size() << "\n";
    F(it, ans.begin(), ans.end()){
        F(jt, (*it)->is.begin(), (*it)->is.end()){
            cout << "http://" << rv[*jt] << " ";
        }
        cout << "\n";
    }
    ret 0;
}