#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    set<int> s;
    s.insert(n);
    map<int,bool> was;
    while(!was[n]){
        was[n]=true;
        n++;
        while(n%10==0)n/=10;
        s.insert(n);
    }
    printf("%i\n",(int)s.size());
    return 0;
}