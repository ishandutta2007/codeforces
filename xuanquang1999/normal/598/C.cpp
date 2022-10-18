//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define fordit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define e 0.0000001
#define double long double

pair<ii, int> v[maxN];
ii ZERO_VEC = mp(0, 0);
int n, ansV1, ansV2;
double ansA;

double angle(ii v1, ii v2) {
    double x1 = v1.ff, x2 = v2.ff, y1 = v1.ss, y2 = v2.ss;
    return acos((x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2)));
}

double angle_to_Ox(ii a) {
    {
        int x = a.ff, y = a.ss;
        if (x > 0 && y == 0) return 0;
        if (x == 0 && y > 0) return M_PI/2;
        if (x < 0 && y == 0) return M_PI;
        if (x == 0 && y < 0) return 3*M_PI/2;
    }
    {
        double x = a.ff, y = a.ss;
//        if (x > 0 && y > 0) return atan(y/x);
//        if (x < 0 && y > 0) return M_PI/2+atan(y/-x);
//        if (x < 0 && y < 0) return M_PI+atan(-y/-x);
//        if (x > 0 && y < 0) return 3*M_PI/2+atan(-y/x);
        if (x > 0) return atan(y/x);
        if (x < 0) return M_PI+atan(y/x);
    }
}

bool cmp(pair<ii, int> a, pair<ii, int> b) {
    return (angle_to_Ox(a.ff) < angle_to_Ox(b.ff));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) {
        scanf("%d%d", &v[i].ff.ff, &v[i].ff.ss);
        v[i].ss = i+1;
    }

    sort(v, v+n, cmp);
    ansA = M_PI*2;
    fto(i, 0, n-1) {
        //double a = angle(v[(i+1)%n].ff, v[i].ff);
        //cout << angle(v[(i+1)%n].ff, v[i].ff) << endl;
        double t = abs(angle_to_Ox(v[(i+1)%n].ff)-angle_to_Ox(v[i].ff));
        double a = min(t, M_PI*2-t);
//        debug(a);
//        debug(angle_to_Ox(v[(i+1)%n].ff));
//        debug(angle_to_Ox(v[i].ff));
//        debug(v[(i+1)%n].ss);
//        debug(v[i].ss);
        if (a < ansA) {
            ansA = a;
            ansV1 = v[(i+1)%n].ss;
            ansV2 = v[i].ss;
        }
    }


    printf("%d %d\n", ansV1, ansV2);

    return 0;
}