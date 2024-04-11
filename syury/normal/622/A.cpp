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

const lint MAXP = 1e9;

lint epos(lint num){
    return num * (num + 1) / 2;
}

lint binsearch(lint pos){
    lint l = 1, r = MAXP;
    while(r - l > 1){
        lint mid = (l + r) / 2;
        if(epos(mid) < pos)
            l = mid + 1;
        else
            r = mid;
    }
    if(epos(l) < pos)
        return r;
    return l;
}

lint n;

int main(){
    cin >> n;
    lint last = binsearch(n);
    if(last == 1){cout << 1 << endl; return 0;}
    lint p1 = epos(last - 1);
    cout << n - p1 << endl;
    return 0;
}