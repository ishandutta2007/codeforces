#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>

using namespace std;
typedef long long int lint;
typedef long double ldb;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    getline(cin, s);
    unsigned int pos = s.find_first_of(" ");
    int num = stoi(s.substr(0, pos));
    s = s.substr(pos + 1);
    size_t pos1 = s.find_first_of(" ");
    pos1++;
    if(s[pos1] == 'w'){
        if(num == 1){cout << 52 << endl;}
        if(num == 2){cout << 52 << endl;}
        if(num == 3){cout << 52 << endl;}
        if(num == 4){cout << 52 << endl;}
        if(num == 5 || num == 6){cout << 53 << endl;}
        if(num == 7){cout << 52 << endl;}
    }
    else{
        if(num <= 29){cout << 12 << endl; return 0;}
        if(num == 30){cout << 11 << endl; return 0;}
        cout << 7 << endl;
    }
    return 0;
}