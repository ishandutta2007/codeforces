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

string s;
int n;

char upcase(char c){
    if ((c>='A')&(c<='Z'))
        return c;
    else return char(int(c)-int('a')+int('A'));
}

char downcase(char c){
    if ((c>='a')&(c<='z'))
        return c;
    else return char(int(c)-int('A')+int('a'));
}

int main(){
    cin>>s;
    cin>>n;
    for (int i=0;i<s.size();i++){
        char c=downcase(s[i]);
        if (int(c)<n+97)c=upcase(c);else c=downcase(c);
        putchar(c);
    }
    return 0;
}