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
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
#define ll long long
#define ld long double
#define uint unsigned int
#define MAXINT 1000000010

// M_PI

#pragma comment(linker, "/STACK:167772160")

/*
int compint (const void* a, const void* b){
    return ((*(int*)a)-(*(int*)b));
}
*/

/*
int compll (const void* a, const void* b){
    return ((*(ll*)a)-(*(ll*)b));
}
*/

/*
int compstr(const void* a, const void* b){
    if(*(string*)a>*(string*)b)
        return 1;
    else if(*(string*)a==*(string*)b)
        return 0;
    else
        return -1;
}
*/



int main(){
    //ios_base::sync_with_stdio(0);]
    string s;
    int k, l, ans;
    cin>>s>>k;
    l=s.size();
    if(k==l)
        cout<<2*k;
    else if(k>l)
        cout<<l+k-((l+k)&1);
    else{
        ans=2*k;
        for(int i(l-k-2); i>=0; i-=2){
            bool f(0);
            for(int j(i); j<=(l-k-2+i)/2; ++j){
                if(s[j]!=s[j+(l+k-i)/2]){
                    f=1;
                    break;
                }
            }
            if(!f)
                ans=k+l-i;
        }
        for(int i(ans/2+1); i<=l/2; ++i){
            for(int j(0); j<=l-i*2;++j){
                if(s.substr(j, i)==s.substr(j+i,i))
                    ans=i*2;
            }
        }
        cout<<ans;
    }
    return 0;
}