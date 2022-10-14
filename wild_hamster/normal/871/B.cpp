#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 12
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[200500],b[250005], c[200500];
ll curp[100500], curb[100500];
ll ansp[100500], ansb[100500], used[100500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        printf("? %d %d\n", i, i);
        fflush(stdout);
        cin >> x;
        a[i] = x;
        if (i < n-1) {
            printf("? %d %d\n", i, i+1);
            fflush(stdout);
            cin >> y;
            b[i] = (x^y);
        }
    }
    for (i = 0; i < n; i++) {
        curb[0] = i;
        for (int j = 1; j < n; j++)
            curb[j] = (curb[j-1]^b[j-1]);
        for (int j = 0; j < n; j++)
            curp[j] = (curb[j]^a[j]);
        bool good = true;
        for (int j = 0; j < n; j++)
            used[j] = 0;
        for (int j = 0; j < n; j++) {
            if (curb[j] >= n)
                good = false;
            if (!used[curb[j]])
                used[curb[j]] = 1;
            else
                good = false;
        }
        for (int j = 0; j < n; j++)
            used[j] = 0;
        for (int j = 0; j < n; j++) {
            if (curp[j] >= n)
                good = false;
            if (!used[curp[j]])
                used[curp[j]] = 1;
            else
                good = false;
        }

        for (int j = 0; j < n; j++) {
            if (curp[curb[j]] != j)
                good = false;
        }
        if (good) {
            k++;
            for (j = 0; j < n; j++)
                ansp[j] = curp[j];
        }
    }
    cout << "!" << endl;
    cout << k << endl;
    for (j = 0; j < n-1; j++)
        cout << ansp[j] << " ";
    cout << ansp[n-1] << endl;
    return 0;
}