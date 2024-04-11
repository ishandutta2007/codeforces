#include <iostream>
#include <string>
#include <assert.h>
#include <map>
#include <string.h>
#include <stdlib.h>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    for(int testcase = 0; testcase < n; testcase++){

        std::string str;
        std::cin >> str;

        bool ans = true;
        bool c[26];
        for(int i = 0; i < 26; i++){
            c[i] = false;
        }

        for(auto it = str.begin(); it != str.end(); it++){
            if(c[*it - 'a']){
                ans = false;
                break;
            }
            c[*it - 'a'] = true;
        }

        bool a = false;
        bool b = false;

        for(int i = 0; i < 26 && ans; i++){
            if(c[i] && !a){
                a = true;
            }
            else if(!c[i] && a && !b){
                b = true;
            }
            else if(c[i] && a && b){
                ans = false;
                break;
            }
        }

        std::cout << (ans ? "Yes" : "No") << "\n";

    }

    return 0;
}