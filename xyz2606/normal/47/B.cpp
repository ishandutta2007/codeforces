#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <bitset>
#include <sstream>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define X first
#define Y second
const int INF = 1e9;

char s[3][10];

map<char, int> id;

struct node
{
    int x;
    char y;
    friend bool operator < (const node &i, const node &j)
    {
        return i.x < j.x;
    }
}a[5];

int main()
{
    scanf("%s%s%s", s[0], s[1], s[2]);
    for(int i = 0; i < 3; ++i)
    {
        if(s[i][1] == '>') swap(s[i][0], s[i][2]);
        ++id[s[i][2]];
    }

    a[0] = (node){id['A'],'A'};
    a[1] = (node){id['B'],'B'};
    a[2] = (node){id['C'],'C'};
    sort(a, a + 3);
    
    //cout << a[0].x << " " << a[0].y << " " << a[1].x << " " << a[1].y << " " << a[2].x << " " << a[2].y << endl;
    
    if(a[0].x != a[1].x && a[1].x != a[2].x)
    {
        printf("%c%c%c\n", a[0].y, a[1].y, a[2].y);
    }
    else printf("Impossible\n");

    return 0;
}