#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define LL long long

char s[110], t[110];

int num[40], nums[40], numt[40];

int main () {
    cin >>s >> t;
    int slen = strlen (s), tlen = strlen (t);
    if (slen == tlen){
        for (int i = 0; i < slen; i++)
            num[s[i] - 'a']++, num[t[i] - 'a']--;
        for (int i = 0; i <30; i++)
            if (num[i]) goto x;
        cout << "array";
        return 0;
    }
    x:;
    int ti = 0;
    for (int i = 0; i < slen; i++)
    {
        if (s[i] == t[ti]) ti++;
        if (ti == tlen) {cout << "automaton"; return 0;}
    }
    for (int i = 0; i < slen; i++)
        nums[s[i] - 'a'] ++;
    for (int i = 0; i < tlen; i++)
        numt[t[i] - 'a'] ++;
    for (int i = 0; i < 30; i++)
        if (nums[i] < numt[i]) goto x1;
    cout << "both";
    return 0;
    x1:;
    cout << "need tree";
}