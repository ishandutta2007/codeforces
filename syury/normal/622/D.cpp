#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
#include<stack>

#define X first
#define Y second

using namespace std;
typedef long long int lint;
typedef long double ldb;

const int inf = 1e9;

lint ans = 1e18;

int n;

vector<int> p, u;

/*void check(){
    lint curr = 0ll;
    for(int i = 1; i <= n; i++){
        int x = -1, y;
        for(int j = 0; j < 2 * n; j++){
            if(p[j] != i)
                continue;
            if(x == -1)
                x = j;
            else
                y = j;
        }
        curr += (n - i) * llabs(i - n + y - x);
    }
    ans = min(ans, curr);
    if(curr == 0){
        for(int i = 0; i < 2 * n; i++){
            printf("%d ", p[i]);
        }
        printf("\n");
    }
}

void solve(int pos){
    if(pos == 2 * n){
        check();
        return;
    }
    for(int i = n; i >= 1; i--){
        if(u[i] == 2)
            continue;
        u[i]++;
        p[pos] = i;
        solve(pos + 1);
        u[i]--;
    }
}*/

//set<pair<int, int> > s;

int main(){
    scanf("%d", &n);
    p.resize(2 * n); u.resize(n + 1); u.assign(n + 1, 0);
    //solve(0);
    deque<int> d1, d2;
    if(n % 2 != 0)
        d1.push_back(n);
    if(n % 2 == 0)
        d2.push_back(n);
    for(int i = (n % 2 == 0) ? n - 1 : n - 2; i >= 1; i -= 2){
        d1.push_front(i);
        d1.push_back(i);
    }
    for(int i = (n % 2 == 0) ? n - 2 : n - 1; i >= 2; i -= 2){
        d2.push_front(i);
        d2.push_back(i);
    }
    int pos = 0;
    while(!d1.empty()){
        p[pos] = d1.front();
        d1.pop_front(); pos++;
    }
     while(!d2.empty()){
        p[pos] = d2.front();
        d2.pop_front(); pos++;
    }
    //if(n % 2 != 0)
        p[2 * n - 1] = n;
    for(int i = 0; i < 2 * n; i++){
        printf("%d ", p[i]);
    }
   /* lint crr = 0ll;
    for(int i = 1; i <= n; i++){
        int x = -1, y;
        for(int j = 0; j < 2 * n; j++){
            if(p[j] != i)
                continue;
            if(x == -1)
                x = j;
            else
                y = j;
        }
        crr += (n - i) * llabs(i - n + y - x);
    }
    printf("\n%lld", crr);*/
    return 0;
}