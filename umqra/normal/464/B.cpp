#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

struct Point
{
    int x, y, z;
    Point () {}
    Point (int x, int y, int z) : x(x), y(y), z(z) {}
    Point operator - (Point a)
    {
        return Point(x - a.x, y - a.y, z - a.z);
    }
    Point operator + (Point a)
    {
        return Point(x + a.x, y + a.y, z + a.z);    
    }
    ll len()
    {
        return (ll)x * x + (ll)y * y + (ll)z * z;
    }
    Point getMin()
    {
        int a = x, b = y, c = z;
        if (a > b)
            swap(a, b);
        if (b > c)
            swap(b, c);
        if (a > b)
            swap(a, b);
        return Point(a, b, c);
    }
    int operator % (Point a)
    {
        return x * a.x + y * a.y + z * a.z;
    }
    int isZero()
    {
        return x == 0 && y == 0 && z == 0;
    }
    bool operator == (Point a)
    {
        return x == a.x && y == a.y && z == a.z;
    }
    bool operator != (Point a)
    {
        return !(*this == a);
    }
};

int pts[8][3];
int curP[3];
int numP[8];
int fourP[4];
int used[8];
int otherP[8];
Point listPts[8], minPoint[8];
const int perm[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

    
void getVectors(Point &a, Point &b, Point &c)
{
    int id = 0;
    for (int i = 1; i < 8; i++)
    {
        if (!used[i])
            continue;
        for (int s = 0; s < 3; s++)
            curP[s] = pts[i][perm[numP[i]][s]];
        Point v = Point(curP[0], curP[1], curP[2]) - Point(pts[0][0], pts[0][1], pts[0][2]);
        if (id == 0)
            a = v;
        else if (id == 1)
            b = v;
        else
            c = v;
        id++;
    }
}

bool checkVectors(Point &a, Point &b, Point &c)
{
    if (a % b != 0 || b % c != 0 || c % a != 0)
        return false;
    if (a.len() != b.len() || b.len() != c.len())
        return false;
    if (a.len() == 0)
        return false;
    return true;
}

void getPoint(Point &a, Point &b, Point &c)
{
    Point A = Point(pts[0][0], pts[0][1], pts[0][2]);
    listPts[0] = A + a + b;
    listPts[1] = A + a + c;
    listPts[2] = A + a + b + c;
    listPts[3] = A + c + b;
}

void printAns()
{
    for (int i = 1; i < 8; i++)
    {
        if (used[i])
        {   
            for (int s = 0; s < 3; s++)
                curP[s] = pts[i][perm[numP[i]][s]];
            for (int s = 0; s < 3; s++)
                pts[i][s] = curP[s];
        }
    }
    puts("YES");
    for (int i = 0; i < 8; i++, puts(""))
    {
        for (int s = 0; s < 3; s++)
            printf("%d ", pts[i][s]);
    }
}

void bruteMainPts(int pos, int cnt)
{
    if (cnt == 3)
    {
        Point a, b, c;
        getVectors(a, b, c);
        getPoint(a, b, c);
        if (!checkVectors(a, b, c))
            return;
        for (int i = 0; i < 4; i++)
            minPoint[i] = listPts[i].getMin();
        int ind = 0;
        for (int i = 1; i < 8; i++)
        {
            if (!used[i])
                otherP[ind++] = i;
        }
        do
        {
            bool ok = true;
            for (int i = 0; i < 4; i++)
            {
                int idP = otherP[fourP[i]];
                if (minPoint[i] != Point(pts[idP][0], pts[idP][1], pts[idP][2]))
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                for (int i = 0; i < 4; i++)
                {
                    int idP = otherP[fourP[i]];
                    pts[idP][0] = listPts[i].x;
                    pts[idP][1] = listPts[i].y;
                    pts[idP][2] = listPts[i].z;
                }
                printAns();
                exit(0);
            }
        } while (next_permutation(fourP, fourP + 4));
        return;
    }
    if (pos == 8)
        return;
    bruteMainPts(pos + 1, cnt);
    used[pos] = 1;
    for (int i = 0; i < 6; i++)
    {
        numP[pos] = i;  
        bruteMainPts(pos + 1, cnt + 1);
    }
    used[pos] = 0;
}

int main()
{
    for (int i = 0; i < 4; i++)
        fourP[i] = i;
    for (int i = 0; i < 8; i++)
    {
        for (int s = 0; s < 3; s++)
            scanf("%d", &pts[i][s]);
        sort(pts[i], pts[i] + 3);
    }

    bruteMainPts(1, 0);

    puts("NO");
    return 0;
}