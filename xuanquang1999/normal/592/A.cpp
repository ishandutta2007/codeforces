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
#define maxN 200005

char a[8][8];
int minB, minW;
vector<int> white[8], black[8];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 0, 7) scanf("%s", a[i]);
    minB = minW = maxN;
    fto(i, 0, 7)
        fto(j, 0, 7) {
            if (a[i][j] == 'B') {
                int k = i+1;
                while (k <= 7 && a[k][j] == '.') ++k;
                if (k == 8) minB = min(minB, 7-i);
            }
            else if (a[i][j] == 'W') {
                int k = i-1;
                while (k >= 0 && a[k][j] == '.') --k;
                if (k == -1) minW = min(minW, i);
            }
        }

    puts((minW <= minB) ? "A" : "B");

    return 0;
}