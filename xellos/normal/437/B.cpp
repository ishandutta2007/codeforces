#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <limits>
#include <string.h>

 //#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;



 int s, lm;
vector<int> t[40];

int main()
{

    cin>>s>>lm;

    int mx=-1;
    for (int i=1;i<=lm;i++){
        for (int j=0;j<=30;j++){
            if ( (i&(1<<j)) == 0){
                continue;
            }
            mx = max(mx , j);
            t[j].pb(i);
            break;
        }
    }
    int flag=0;
    int i=mx;
    vector<int> ans;
    while (s >= 0){
        if (i == -1){
            flag=1;
            break;
        }
        while (t[i].size() > 0 && s >= (1<<i) ){
            s-=(1<<i);
            ans.pb(t[i][0]);
            t[i].erase(t[i].begin()+0);
        }
        if (s == 0){
            break;
        }
        i--;
    }
    if (flag == 1){
        cout<<"-1\n";
    } else {
        cout<<ans.size()<<"\n";
        for (int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}