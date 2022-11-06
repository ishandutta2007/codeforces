#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int v[100005];
vector<int> a;

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, m=0, b=0, i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &v[i]);
    for(i=1; i<n; i++){
        if (v[i-1]<v[i] && !m) {m=1; a.push_back(i); a.push_back(i+1);}
        if (v[i-1]>v[i] && !b) {b=1; a.push_back(i); a.push_back(i+1);}
    }
    if (!m || !b) printf("0");
    else printf("3\n%d %d %d", a[0], a[2], a[3]);
}