#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <math.h>

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int sl;
    std::cin >> sl;
    std::string s;
    std::cin >> s;

    bool ans = true;;
    int leftamount = 0;
    int rightamount = 0;

    int nowleft = 0;
    int nowright = 0;

    if(sl % 2 == 1 || s[0] == ')' || s[sl - 1] == '('){
        ans = false;
    }
    else{
        for(int i = 0; i < sl; i++){
            if(s[i] == '('){
                leftamount++;
            }
            else if(s[i] == ')'){
                rightamount++;
            }
        }

        for(int i = 0; i < sl; i++){
            if(i != 0 && nowleft == nowright || nowright > nowleft){
                ans = false;
                break;
            }
            if(s[i] == '('){
                nowleft++;
                leftamount--;
                continue;
            }
            else if(s[i] == ')'){
                nowright++;
                rightamount--;
                continue;
            }
            if(leftamount + nowleft < sl / 2){
                s[i] = '(';
                nowleft++;
            }
            else{
                s[i] = ')';
                nowright++;
            }
        }
    }
    if(nowleft != nowright){
        ans = false;
    }

    std::cout << (ans ? s : ":(") << "\n";

    return 0;
}