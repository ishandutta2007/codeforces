#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <complex>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100100;
char s[N];
int a[1000];
int b[1000];
char p[] = "Bulbasaur";

int main()
{
    scanf(" %s ", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        a[s[i]]++;
    n = strlen(p);
    for (int i = 0; i < n; i++)
        b[p[i]]++;
    int ans = N;
    for (int i = 0; i < 1000; i++)
        if (b[i] != 0)
            ans = min(ans, a[i] / b[i]);
    printf("%d\n", ans);


    return 0;
}