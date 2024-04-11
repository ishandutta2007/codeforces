#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m;
pii arr[100100];
set<pii> se;
vector<pdd> ran;
const double PI = acos(-1), eps = 1e-8;

double dis(pdd a, pdd b) {
    return sqrt(max(0.0,(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

double nor(double ang) {
    while(ang>2*PI-eps) ang-=2*PI;
    while(ang<-eps) ang+=2*PI;
    return ang;
}

pdd origin = pdd(0.0,0.0);
int getv(double s, double e, vector<double> &vec) {
    return upper_bound(vec.begin(),vec.end(),e)-lower_bound(vec.begin(),vec.end(),s);
}
bool isin(double s, double e, double x) {
    if (s<e) return s<=x&&x<=e;
    return x<=e||s<=x;
}
int nxt[100100];
int solve(int idx, int lim) {
    int p = idx, c = 0;
    while(p<idx+n&&c<=lim) {
        p = nxt[p%n]+p/n*n;
        c++;
    }
    return c;
}
bool ok(double R) {
    ran.clear();
    for (int i=0;i<n;i++) {
        if (dis(arr[i],origin)<R+eps) return 0;
        double the = atan2(arr[i].y,arr[i].x);
        double phi = acos(R/dis(arr[i],origin));
        ran.push_back(pdd(nor(the-phi),nor(the+phi)));
    }
    vector<double> ed;
    for (pdd &v : ran) ed.push_back(v.y);
    sort(ed.begin(),ed.end());
    sort(ran.begin(),ran.end(),[](pdd &a, pdd &b){return a.y<b.y;});
    int mini = n+10, mint = -1;
    for (int i=0;i<ran.size();i++) {
        pdd &v = ran[i];
        int t = 0;
        if (v.x<v.y) t = getv(v.x,v.y,ed);
        else t = getv(0,v.y,ed)+getv(v.x,2*PI,ed);
        if (mini>t) {
            mini=t;
            mint=i;
        }
    }
    int p = 1;
    while(p<n){
        if (!isin(ran[p].x,ran[p].y,ran[0].y)) break;
        p++;
    }
    nxt[0] = p;
    for (int i=1;i<n;i++) {
        while(p<n+i) {
            if (!isin(ran[p%n].x,ran[p%n].y,ran[i].y)) break;
            p++;
        }
        nxt[i] = p;
    }
    int ans = m+10;
    for (int i=0;i<ran.size();i++) {
        if (isin(ran[mint].x,ran[mint].y,ran[i].y)) {
            ans = min(ans,solve(i,ans));
            if (ans<=m) return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) {
        scanf("%d%d",&arr[i].x,&arr[i].y);
        if (arr[i].x==0&&arr[i].y==0) {
            puts("0.0");
            exit(0);
        }
        se.insert(arr[i]);
    }
    n = se.size();
    auto it = se.begin();
    int p = 0;
    while(it!=se.end()) {
        arr[p++] = *it;
        it++;
    }
    double s = 1e-8, e = 2e5;
    for (int i=0;i<50;i++) {
        double m = (s+e)/2;
        if (ok(m)) s=m;
        else e=m;
    }
    printf("%.20f\n",s);

    return 0;
}