#include<string>
#include<vector>
#include<unordered_map>
#include<utility>
#include<set>
#include<iostream>
#include<list>

using namespace std;

typedef long long int lint;

lint n;

lint d(lint k){
    return n/k;
}

lint ans = 0ll;

int p[4] = {2, 3, 5, 7};

int main(){
    cin >> n;
    ans = d(2) + d(3) + d(5) + d(7);
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            if(i == j)
                continue;
            ans -= d(p[i] * p[j]);
            for(int k = j + 1; k < 4; k++){
                if(k == i || k == j)
                    continue;
                ans += d(p[i] * p[j] * p[k]);
            }
        }
    }
    ans -= d(2 * 3 * 5 * 7);
    cout << n - ans << endl;
	return 0;
}