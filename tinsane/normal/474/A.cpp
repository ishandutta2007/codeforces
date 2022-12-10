#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <iomanip>
#include<map>
#include <string>
#include<list>
#include<stack>
#include<algorithm>
#include <queue>
#include <time.h>
#include<functional>
#include<set>
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
#define ll long long
#define ld long double
#define STR string
#define MAXINT 1000000010
#define MAXLL 1000000000000000000
#define PII pair<int,int> 
#define VI vector<int> 
#define VVI vector<vector<int>> 
#define _10POW9PLUS7 1000000007 
//  8739
#pragma comment(linker, "/STACK:167772160")

char convR(char c){
    switch (c){
    case 'q':
        return 'w';
    case 'w':
        return 'e';
    case 'e':
        return 'r';
    case 'r':
        return 't';
    case 't':
        return 'y';
    case 'y':
        return 'u';
    case 'u':
        return 'i';
    case 'i':
        return 'o';
    case 'o':
        return 'p';
    case 'a':
        return 's';
    case 's':
        return 'd';
    case 'd':
        return 'f';
    case 'f':
        return 'g';
    case 'g':
        return 'h';
    case 'h':
        return 'j';
    case 'j':
        return 'k';
    case 'k':
        return 'l';
    case 'l':
        return ';';
    case 'z':
        return 'x';
    case 'x':
        return 'c';
    case 'c':
        return 'v';
    case 'v':
        return 'b';
    case 'b':
        return 'n';
    case 'n':
        return 'm';
    case 'm':
        return ',';
    case ',':
        return '.';
    case '.':
        return '/';
    }
}

char convL(char c){
    switch (c){
    case 'p':
        return 'o';
    case 'o':
        return 'i';
    case 'i':
        return 'u';
    case 'u':
        return 'y';
    case 'y':
        return 't';
    case 't':
        return 'r';
    case 'r':
        return 'e';
    case 'e':
        return 'w';
    case 'w':
        return 'q';
    case ';':
        return 'l';
    case 'l':
        return 'k';
    case 'k':
        return 'j';
    case 'j':
        return 'h';
    case 'h':
        return 'g';
    case 'g':
        return 'f';
    case 'f':
        return 'd';
    case 'd':
        return 's';
    case 's':
        return 'a';
    case '/':
        return '.';
    case '.':
        return ',';
    case ',':
        return 'm';
    case 'm':
        return 'n';
    case 'n':
        return 'b';
    case 'b':
        return 'v';
    case 'v':
        return 'c';
    case 'c':
        return 'x';
    case 'x':
        return 'z';
    }
}

int main(){
    char c;
    string s;
    cin>>c>>s;
    if(c=='R')
        for(int i(0);i<s.size();++i)
            s[i]=convL(s[i]);
    else
        for(int i(0);i<s.size();++i)
            s[i]=convR(s[i]);
    cout<<s;
    return 0;
}