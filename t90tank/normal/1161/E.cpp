#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const int maxn = 200000;

vector<pii> q;
vi a;
int n;
int s2[maxn];
int s[maxn];
int c[maxn];
int cc[maxn];
char st[maxn];
vi r;
vi ans[3];

void geta() {
    a.clear();
    if (!q.empty()) {
        printf("Q %d", q.size());
        for (auto i : q)
            printf(" %d %d", i.fir, i.sec);
        puts("");
        fflush(stdout);
        scanf("%s", st);
        int len = strlen(st);
        for (int i = 0; i < len; i++)
            a.pb(st[i]-'0');
    }
//    a.clear();
//    for (auto i : q)
//        a.pb(cc[i.fir]==cc[i.sec]);
}

int main() {
    int t;
    scanf("%d", &t);
//    t = 2;
    while (t--) {
        scanf( "%d", &n );
//        n = 6;
//        for (int i = 1; i <= n; ++i)
//            cc[i] = i / 3;

        q.clear();
        for (int i = 1; i+1 <= n; i+=2) q.pb({i,i+1});
        geta();
        int j = 2;
        for (auto i : a) { s[j] = i; j += 2; }

        q.clear();
        for (int i = 2; i+1 <= n; i+=2) q.pb({i,i+1});
        geta();
        j = 3;
        for (auto i : a) { s[j] = i; j += 2; }

        r.clear();
        r.pb(1);
        for (int i = 2; i <= n; ++i)
            if (s[i] == 0) r.pb(i);
//        for (auto x : r) cout<<x<<endl;

        if (r.size() == 1) {
            printf( "A %d 0 0\n", n);
            for (int i = 1; i <= n; ++i) printf("%d ", i);
            puts("");puts("");puts("");
            fflush(stdout);
            continue;
        }

        q.clear();
        for (int i = 0; i+2 < r.size(); i+=4) q.pb({r[i],r[i+2]});
        for (int i = 1; i+2 < r.size(); i+=4) q.pb({r[i],r[i+2]});
        geta();
        j = 0;
        for (int i = 0; i+2 < r.size(); i+=4) { s2[i+2] = a[j]; j++; }
        for (int i = 1; i+2 < r.size(); i+=4) { s2[i+2] = a[j]; j++; }

        q.clear();
        for (int i = 2; i+2 < r.size(); i+=4) q.pb({r[i],r[i+2]});
        for (int i = 3; i+2 < r.size(); i+=4) q.pb({r[i],r[i+2]});
        geta();
        j = 0;
        for (int i = 2; i+2 < r.size(); i+=4) { s2[i+2] = a[j]; j++; }
        for (int i = 3; i+2 < r.size(); i+=4) { s2[i+2] = a[j]; j++; }

        c[r[0]] = 0; c[r[1]]=1;
       // for (int i = 2; i < r.size(); ++i) cout<<s2[i]<<";"; puts("");
        for (int i = 2; i < r.size(); ++i)
            if (s2[i] == 1) c[r[i]] = c[r[i-2]];
            else c[r[i]] = 3-c[r[i-2]]-c[r[i-1]];
        for (int i = 2; i <= n; ++i)
            if (s[i] == 1) c[i] = c[i-1];
        for (int i = 0; i < 3; ++i) ans[i].clear();
        //for (int i = 1; i <= n; ++i) {
          //  cout<<c[i]<<' '<<s[i]<<endl;
       // }
        for (int i = 1; i <= n; ++i) ans[c[i]].pb(i);
        printf( "A %d %d %d\n", ans[0].size(), ans[1].size(), ans[2].size());
        for (auto i : ans[0]) printf( "%d ", i); puts("");
        for (auto i : ans[1]) printf( "%d ", i); puts("");
        for (auto i : ans[2]) printf( "%d ", i); puts("");
        fflush(stdout);
    }
}