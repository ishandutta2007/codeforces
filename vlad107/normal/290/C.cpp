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

int main(){
    int tux;
    cin>>tux;
    int foo=0,bar=0,baz=0,quz=1;
    for (int i=0;i<tux;i++){
        int pur;
        cin>>pur;
        foo+=pur;
        bar+=1;
        if (foo*quz>baz*bar){
            baz=foo;
            quz=bar;
        }
    }
    printf("%.10lf\n",(baz+.0)/quz);
    return 0;
}