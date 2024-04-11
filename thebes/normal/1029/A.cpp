#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, k, i, j, v;

int main(){
    cin >> n >> k >> t;
    for(i=1;i<t.size();i++){
            bool mat = 0;
        for(j=0;i+j<t.size();j++){
            if(t[i+j]!=t[j]) mat=1;
        }
        if(!mat){v=i; break;}
    }
    if(!v) v = t.size();
    s = t;
    for(i=1;i<k;i++){
        for(j=t.size()-v;j<t.size();j++)
            s += t[j];
    }
    cout<< s.c_str() << endl;
    return 0;
}