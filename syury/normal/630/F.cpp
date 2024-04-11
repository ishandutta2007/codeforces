#include<string>
#include<vector>
#include<unordered_map>
#include<utility>
#include<set>
#include<iostream>
#include<list>

using namespace std;

typedef unsigned long long int lint;

lint n;

lint c(lint i, lint j){
    lint ans = 1ll;
    for(lint d = i; d > i - j; d--){
        ans *= d;
        ans /= (i - d + 1);
    }
   //for(lint k = 1ll; k <= j; k++)
     //   ans /= k;
    return ans;
}

int main(){
    cin >> n;
    cout << c(n, 5) + c(n, 6) + c(n, 7);
	return 0;
}