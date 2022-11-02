#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <iomanip>
#include <assert.h>

#define mp make_pair
#define pb push_back
#define N 500500

typedef long long ll;

using namespace std;

int n,x,t,a[33];
ll res;

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&x);
        t=0;while (x){t+=x%2;x/=2;}
        res+=a[t];a[t]++;
    }
    cout<<res;
    return 0;
}