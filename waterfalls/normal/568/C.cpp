#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MP make_pair
#define A first
#define B second

char alph[100];
int n,m,l;
char s[213];
vector<pair<int,int> > adj_[213][2];
    vector<pair<int,int> >& adj(pair<int,int> x) { return adj_[x.A][x.B]; }
int visited_[213][2];
    int& visited(pair<int,int> x) { return visited_[x.A][x.B]; }
vector<pair<int,int> > topo;
int val[213];

void dfs(pair<int,int> x) {
    visited(x) = 1;
    for (pair<int,int> i: adj(x)) if (!visited(i)) dfs(i);
    topo.push_back(x);
}

bool check() {
    for (int i=0;i<n;i++) for (int j=0;j<2;j++) {
        for (pair<int,int> x: adj(MP(i,j))) {
            if (val[i]==j && val[x.A]!=x.B) return false;
        }
    }
    return true;
}

void set(pair<int,int> x) {
    visited(x) = 1;
    if (val[x.A]==2) val[x.A] = x.B;
    for (pair<int,int> i: adj(x)) if (!visited(i)) set(i);
}

bool make(int fix) {
    for (int i=0;i<n;i++) val[i] = 2;
    for (int i=0;i<n;i++) for (int j=0;j<2;j++) visited(MP(i,j)) = 0;
    for (int i=0;i<fix;i++) set(MP(i,(alph[s[i]-'a']=='V')));
    for (int i=0;i<fix;i++) val[i] = (alph[s[i]-'a']=='V');
    for (pair<int,int> i: topo) set(i);
    return check();
}

bool can(int change) {
    if (change>n-1) return make(n);
    for (int i=change;i<=n;i++) {
        if (i==n) return make(n);
        bool hasv = 0;
        bool hasc = 0;
        int ok = 0;
        int low = (i==change) ? s[i]-'a' : -1;
        for (int j=low+1;j<l;j++) {
            if ((alph[j]=='V' && hasv) || (alph[j]=='C' && hasc)) continue;
            if (alph[j]=='V') hasv = 1;
            else hasc = 1;
            s[i] = 'a'+j;
            if (make(i+1)) {
                ok = 1;
                break;
            }
        }
        if (!ok) return false;
    }
}

int main() {
    scanf(" %s%d%d",&alph,&n,&m);
    l = strlen(alph);
    for (int i=0;i<m;i++) {
        int x,y;
        char a,b;
        scanf("%d %c%d %c",&x,&a,&y,&b);
        x-=1; y-=1;
        adj(MP(x,a=='V')).push_back(MP(y,b=='V'));
        a = 'V'+'C'-a; b = 'V'+'C'-b;
        adj(MP(y,b=='V')).push_back(MP(x,a=='V'));
    }
    for (int i=0;i<n;i++) for (int j=0;j<2;j++) if (!visited(MP(i,j))) dfs(MP(i,j));
    scanf(" %s",&s);
    for (int diff=n;diff>=0;diff--) {
        if (can(diff)) {
            printf("%s\n",s);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}