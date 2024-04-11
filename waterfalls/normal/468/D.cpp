#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n;
vector<pair<int,int> > adj[100013];
int s[100013];
long long d[100013];

vector<int> centroid;
void dfs(int x, int p) {
    bool ok = 1;
    s[x] = 1;
    for (pair<int,int>& i: adj[x]) if (i.A!=p) {
        dfs(i.A,x);
        if (s[i.A]>n/2) ok = 0;
        s[x]+=s[i.A];
    }
    if (n-s[x]>n/2) ok = 0;
    if (ok) centroid.push_back(x);
}

vector<vector<int> > st;
int which[100013];
void dfs2(int x, int p, long long dep) {
    d[x] = dep;
    st.back().push_back(x);
    which[x] = st.size()-1;
    for (pair<int,int>& i: adj[x]) if (i.A!=p) dfs2(i.A,x,dep+i.B);
}

set<int> small;
set<pair<int,int> > sizes;
int has[100013];
void setup(int c) {
    st.clear();
    for (pair<int,int>& i: adj[c]) {
        st.push_back(vector<int>());
        dfs2(i.A,c,i.B);
    }
    st.push_back(vector<int>());
    st.back().push_back(c);
    d[c] = 0;
    which[c] = st.size()-1;
    for (vector<int>& v: st) {
        sort(v.begin(),v.end());
        v.push_back(n+1);
        reverse(v.begin(),v.end());
    }
    small.clear();
    sizes.clear();
    for (int i=0;i<st.size();i++) {
        small.insert(st[i].back());
        has[i] = 2*st[i].size()-2;
        sizes.insert(MP(has[i],i));
    }
}

void remove(int i) {
    small.erase(st[i].back());
    sizes.erase(MP(has[i],i));
}
void insert(int i) {
    small.insert(st[i].back());
    sizes.insert(MP(has[i],i));
}

vector<int> solve(int c) {
    setup(c);
    vector<int> match;
    for (int i=1;i<=n;i++) {
        if (c==i && (i==n || (--sizes.end())->A<=n-i)) {
            if (*small.begin()==c) {
                match.push_back(i);
                remove(which[i]);
                st[which[i]].pop_back();
                has[which[i]]-=2;
                insert(which[i]);
                continue;
            }
        }
        remove(which[i]);

        int where = -1;
        if ((--sizes.end())->A>n-i && (i!=n-1 || (--sizes.end())->B!=which[c])) where = (--sizes.end())->B;
        else where = which[*small.begin()];

        match.push_back(st[where].back());
        remove(where);
        st[where].pop_back();
        has[where]-=1;
        insert(where);

        has[which[i]]-=1;
        insert(which[i]);
    }
    return match;
}

int main() {
    scanf("%d",&n);
    if (n==1) return printf("0\n1\n"),0;
    for (int i=2;i<=n;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(MP(v,w));
        adj[v].push_back(MP(u,w));
    }
    dfs(1,-1);
    vector<int> one = solve(centroid[0]);
    if (centroid.size()==2) {
        vector<int> two = solve(centroid[1]);
        if (two<one) one = two;
    }
    long long ans = 0;
    for (int i=1;i<=n;i++) ans+=2*d[i];
    printf("%lld\n",ans);
    for (int& i: one) printf("%d ",i);
    printf("\n");

    return 0;
}