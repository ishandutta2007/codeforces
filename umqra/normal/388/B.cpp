#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int N = (int)1e3 + 100;
int mv = 3;
int g[N][N];
int vertex[N], deep[N];

void addEdge(int a, int b)
{
    g[a][b] = g[b][a] = 1;
}

void makePath(int t)
{
    int lst = 1;      
    for (int i = 0; i < t; i++)
    {               
        vertex[i] = lst;
        deep[lst] = i;
        addEdge(lst, mv);
        addEdge(lst, mv + 1);
        if (i == t - 1)
        {
            vertex[t] = 2;
            deep[2] = t;
            addEdge(mv, 2);
            addEdge(mv + 1, 2);
            mv += 2;
            break;
        }
        addEdge(mv, mv + 2);
        addEdge(mv + 1, mv + 2);
        lst = mv + 2;     
        mv += 3;
    }   
}

void addPath(int d)
{                                       
    int lst = vertex[d];
    for (int i = d; i < deep[2]; i++)
    {                     
        if (i == deep[2] - 1)
        {
            addEdge(lst, mv);
            addEdge(mv, 2);
            mv++;
            break;
        }
        addEdge(lst, mv);
        addEdge(mv, mv + 1);
        lst = mv + 1;
        mv += 2;
    }
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int k;
    scanf("%d", &k);
    if (k == 1)
    {
        addEdge(1, 2);
    }

    for (int i = 31; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            makePath(i);
            break;
        }
    }

    for (int i = 31; i >= 0; i--)
    {                                  
        if (k & (1 << i))
            addPath(i);
    }
             
    printf("%d\n", mv);
    for (int i = 1; i <= mv; i++, puts(""))
        for (int s = 1; s <= mv; s++)
            printf("%c", (g[i][s] == 1 ? 'Y' : 'N'));
        
    return 0;
}