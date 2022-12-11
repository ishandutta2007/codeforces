#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
using namespace std;

const int INF = (int)1e9;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

// const string p[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

double bst = 0;
int used[100];
pii pts[100];
int listP[100];
int bstP[100];
int ind = 0;

double sqr(int a)
{
    return a * a;
}

double getDist(int a, int b)
{
    return sqrt(sqr(pts[a].X - pts[b].X) + sqr(pts[a].Y - pts[b].Y));
}

void choose(int cnt, int lst, double res)
{
    if (cnt == 4)
    {
        if (res > bst)
        {
            bst = res;
            for (int i = 0; i < cnt; i++)
                bstP[i] = listP[i];
        }
        return;
    }
    for (int i = 0; i < ind; i++)
    {
        if (!used[i])
        {
            double a = (lst == -1 ? 0 : getDist(lst, i));
            used[i] = 1;
            listP[cnt] = i;
            choose(cnt + 1, i, res + a);
            used[i] = 0;
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= min(n, 3); i++)
        for (int s = 0; s <= min(m, 3); s++)
        {
            pts[ind++] = mp(i, s);
            if (n - i >= 0 && m - s >= 0)
                pts[ind++] = mp(n - i, m - s);
        }
    sort(pts, pts + ind);
//  for (int i = 0; i < ind; i++)
//      cout << pts[i].X << ":" << pts[i].Y << endl;
    ind = unique(pts, pts + ind) - pts;
    
    choose(0, -1, 0);
    for (int i = 0; i < 4; i++)
        cout << pts[bstP[i]].X << " " << pts[bstP[i]].Y << endl;
    
    return 0;
}