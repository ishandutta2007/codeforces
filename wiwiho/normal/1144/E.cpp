#include <iostream>
#include <assert.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int k;
    std::cin >> k;

    std::string s, t;
    std::cin >> s >> t;

    std::vector<int> sv(k + 1);
    std::vector<int> tv(k + 1);

    for(int i = 0; i < k; i++){
        sv[i + 1] = s[i] - 'a';
        tv[i + 1] = t[i] - 'a';
    }

    std::vector<int> ans(k + 1);

    for(int i = k; i > 0; i--){
        ans[i] += sv[i] + tv[i];
        if(ans[i] >= 26){
            ans[i] -= 26;
            ans[i - 1]++;
        }
    }

    for(int i = 0; i < k + 1; i++){
        if(ans[i] % 2 != 0){
            ans[i + 1] += 26;
        }
        ans[i] /= 2;
    }

    for(int i = 1; i < k + 1; i++){
        std::cout << (char)('a' + ans[i]);
    }
    std::cout << "\n";

    return 0;
}