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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

set<pair<int, string> > st;
map<string, int> cnt;
set<pair<int, string> >::iterator it;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string name, tmp1, tmp2, tmp3, ss;
    int i, n, a;
    cin >> name >> n;
    for(i = 0; i < n; i++){
        cin >> tmp1 >> tmp3;
        if (tmp3 == "posted"){
            a = -15;
            cin >> tmp3;
        }
        else if (tmp3 == "commented"){
            a = -10;
            cin >> tmp3;
        } 
        else{
            a = -5;
        }
        cin >> tmp2;
        tmp2 = tmp2.substr(0, tmp2.length() - 2);
        ss = "";
        if (tmp1 == name){
            ss = tmp2; 
        }
        if (tmp2 == name){
            ss = tmp1;
        }
        if (ss == ""){
            cnt[tmp1] += 0;
            cnt[tmp2] += 0;
            st.insert(mp(cnt[tmp1], tmp1));
            st.insert(mp(cnt[tmp2], tmp2));
            cin >> tmp3;
            continue;
        }
        cnt[ss] += 0;
        //st.insert(mp(cnt[ss], ss));
        st.erase(mp(cnt[ss], ss));
        cnt[ss] += a;
        st.insert(mp(cnt[ss], ss));
        cin >> tmp3;
    }
    for(it = st.begin(); it != st.end(); it++){
        cout << it->second << endl;
    }
}