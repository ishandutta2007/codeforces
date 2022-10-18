using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 50005
#define maxP 1000000000

struct task {
    int p;
    int s;
    int t;
    int id;
    ll finish;
    inline bool operator < (const task &b) const
    {
        return (p < b.p);
    }
};

task a[maxN];
int n, pos, maxT, posP[maxN], nPosP;
ll T;

bool cmp1(task a, task b) {
    return (a.t < b.t);
}

bool cmp2(task a, task b) {
    return (a.id < b.id);
}

void Dowork() {
    set<pair<task, int> > s; s.clear();
    s.insert(mp(a[0], 0));
    ll curT = a[0].t;
    fto(i, 1, n-1) {
        int b = a[i].t-a[i-1].t;
        while (b > 0 && !s.empty()) {
            set<pair<task, int> >::iterator it = --s.end();
            task top = (*it).fi; int setid = (*it).se;
            s.erase(it);
            if (top.s <= b) {
                curT+=top.s;
                a[setid].finish = curT;
                b-=top.s;
            }
            else {
                curT+=b;
                top.s-=b;
                s.insert(mp(top, setid));
                b = 0;
            }
            //printf("%d %d %d %d %I64d %d\n", top.t, top.s, top.p, top.id, top.finish, setid);
        }
        curT+=b;
        s.insert(mp(a[i], i));
        //debug(curT);
    }
    while (!s.empty()) {
        set<pair<task, int> >::iterator it = --s.end();
        task top = (*it).fi; int setid = (*it).se;
        s.erase(it);
        curT+=top.s;
        a[setid].finish = curT;
        //printf("%d %d %d %d %I64d %d\n", top.t, top.s, top.p, top.id, top.finish, setid);
        //debug(curT);
    }
}

int main () {
    //freopen("input.txt", "r", stdin);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) {
        scanf("%d%d%d", &a[i].t, &a[i].s, &a[i].p);
        a[i].id = i;
        maxT = max(maxT, a[i].t);
    }
    cin >> T;

    sort(a, a+n);

    if (a[0].p > 1) posP[nPosP] = a[0].p-1, ++nPosP;
    fto(i, 1, n-1)
    if (a[i-1].p+1 != a[i].p) posP[nPosP] = a[i].p-1, ++nPosP;
    if (a[n-1].p < maxP) posP[nPosP] = a[n-1].p+1, ++nPosP;

    //fto(i, 0, nPosP-1) debug(posP[i]);

    sort(a, a+n, cmp1);

    //fto(i, 0, n-1) printf("%d %d %d %d\n", a[i].t, a[i].s, a[i].p, a[i].id);

    fto(i, 0, n-1)
        if (a[i].p == -1) pos = i;

    int l = 0, r = nPosP-1;
    while (l <= r) {
        int mid = (l+r)/2;
        a[pos].p = posP[mid];
        Dowork();
        //debug(a[pos].finish);
        if (a[pos].finish < T) r = mid-1;
        else if (a[pos].finish > T) l = mid+1;
        else {
            printf("%d\n", posP[mid]);
            sort(a, a+n, cmp2);
            fto(i, 0, n-1) printf("%I64d ", a[i].finish);
            break;
        }
    }


    return 0;
}