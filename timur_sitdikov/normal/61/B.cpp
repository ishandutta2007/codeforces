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
#define xx first
#define yy second

string correct(string &s)
{
    string ans;
    for(int i = 0; i < (int)s.length(); i++)
        if (s[i]>='a' && s[i]<='z')
            ans.pb(s[i]);
        else if (s[i]>='A' && s[i]<='Z')
            ans.pb(s[i] - 'A' + 'a');
    return ans;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    string s1, s2, s3, tmp;
    set<string> st;
    int i, n;
    cin >> s1 >> s2 >> s3;
    s1 = correct(s1);
    s2 = correct(s2);
    s3 = correct(s3);
    st.insert(s1+s2+s3);
    st.insert(s1+s3+s2);
    st.insert(s2+s1+s3);
    st.insert(s2+s3+s1);
    st.insert(s3+s1+s2);
    st.insert(s3+s2+s1);
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> tmp;
        tmp = correct(tmp);
        if (st.find(tmp)!=st.end())
            cout << "ACC" << endl;
        else
            cout << "WA" << endl;
    }


}