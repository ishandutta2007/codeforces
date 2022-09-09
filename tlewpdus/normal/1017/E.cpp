#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll ccw(pll a, pll b, pll c) {
    return a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
}

int n, m;
vector<pll> arr, brr;
vector<pll> ach, bch;

ll dis(pll a, pll b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

pll piv;
bool cmp(pll a, pll b) {
    return ccw(piv,a,b)>0||(ccw(piv,a,b)==0&&dis(piv,a)<dis(piv,b));
}

void chull(vector<pll> &arr, vector<pll> &ch) {
    int i, n = arr.size();
    pll mini = arr[0]; int t = 0;
    for (i=0;i<n;i++) {
        if (mini>arr[i]) {
            mini=arr[i];
            t = i;
        }
    }
    swap(arr[0],arr[t]);
    piv = arr[0];
    sort(arr.begin()+1,arr.end(),cmp);
    ch.push_back(piv);
    for (i=1;i<n;i++) {
        while(ch.size()>=2&&ccw(ch[(int)ch.size()-2],ch.back(),arr[i])<=0) ch.pop_back();
        ch.push_back(arr[i]);
    }
}

pll rot(pll a) {
    return pll(-a.y,a.x);
}

void rot(vector<pll> &arr) {
    int i;
    for (i=0;i<arr.size();i++) arr[i] = rot(arr[i]);
}

void print(int b) {
    puts(b?"YES":"NO");
    exit(0);
}

bool issame() {
    int i, t = 0, n = ach.size();
    pll mini = ach[0];
    for (i=0;i<ach.size();i++) {
        if (mini>ach[i]) {
            mini=ach[i];
            t = i;
        }
    }
    for (i=0;i<bch.size();i++) {
        if (ach[(i+t)%n].x-bch[i].x!=ach[t].x-bch[0].x||
            ach[(i+t)%n].y-bch[i].y!=ach[t].y-bch[0].y) return false;
    }
    return true;
}

void preKMP(vector<ll> pattern, int f[])
{
    int m = pattern.size(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}

//check whether target string contains pattern
bool KMP(vector<ll> pattern, vector<ll> target)
{
    int m = pattern.size();
    int n = target.size();
    int f[m];
    preKMP(pattern, f);
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = f[k];
    }
    return 0;
}

vector<ll> ax, bx;
int main() {
    int i;

    scanf("%d%d",&n,&m); arr.resize(n); brr.resize(m);
    for (i=0;i<n;i++) scanf("%lld%lld",&arr[i].x,&arr[i].y);
    for (i=0;i<m;i++) scanf("%lld%lld",&brr[i].x,&brr[i].y);
    chull(arr,ach); chull(brr,bch);
    //for (pll &v : ach) printf("%lld %lld\n",v.x,v.y);
    //printf("!");
    //for (pll &v : bch) printf("%lld %lld\n",v.x,v.y);
    if (ach.size()!=bch.size()) print(0);
    if (ach.size()==2) {
        print(dis(ach[0],ach[1])==dis(bch[0],bch[1]));
    }
    for (i=0;i<ach.size();i++) {
        pll a = ach[i], b = ach[(i+1)%ach.size()], c = ach[(i+2)%ach.size()];
        ax.push_back(dis(a,b));
        ax.push_back(ccw(a,b,c));
    }
    for (i=0;i<bch.size();i++) {
        pll a = bch[i], b = bch[(i+1)%bch.size()], c = bch[(i+2)%bch.size()];
        bx.push_back(dis(a,b));
        bx.push_back(ccw(a,b,c));
    }
    int sz = bx.size();
    for (i=0;i<sz;i++) bx.push_back(bx[i]);
    print(KMP(ax,bx));

    return 0;
}