//
//  main.cpp
//  HelloWorld
//
//  Created by  on 2017/4/7.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int n,k,cur,curn,p[10010] = {0};
    bool ans = false,curans;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>cur;
        curans = true;
        for(int j=0;j<10000;j++)p[j] = 0;
        for(int j = 0;j<cur;j++){
            cin>>curn;
            if(curn<0&&p[-1*curn] == 1){
                curans = false;
            }else if(curn>0&&p[curn] == -1){
                curans = false;
            }else if(curn>0){
                p[curn] = 1;
            }else if(curn<0){
                p[-1*curn] = -1;
            }
        }
        if(curans){
            ans = true;
            break;
        }
    }
    cout<<((ans)? ("YES") : ("NO")) << endl;
    return 0;
}