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

string s;

int toi(char c){
    return c - '0';
}

void out(int mins){
    int h = mins/60;
    int m = mins%60;
    if(h < 10)
        cout << "0" << h;
    else
        cout << h;
    cout << ":";
    if(m < 10)
        cout << "0" << m;
    else
        cout << m;
}

int main(){
    cin >> s;
    int mins = toi(s[0]) * 10 * 60 + toi(s[1]) * 60 + toi(s[3]) * 10 + toi(s[4]);
    int a;
    cin >> a;
    mins += a;
    mins %= 24 * 60;
    out(mins);
    return 0;
}