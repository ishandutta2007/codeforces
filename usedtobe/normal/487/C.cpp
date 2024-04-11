#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;

ll power[100010];

int main(void){
    int N,i;
    
    cin >> N;
    
    if(N == 1){
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }
    
    if(N == 4){
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 3 << endl;
        cout << 2 << endl;
        cout << 4 << endl;
        return 0;
    }
    
    for(i=2;i*i<=N;i++) if(N%i == 0){
        cout << "NO" << endl;
        return 0;
    }
    
    int g;
    while(1){
        g = rand() % (N - 1) + 1;
        ll G = 1;
        for(i=1;;i++){
            G = G * g % N;
            if(G == 1) break;
        }
        if(i == N-1) break;
    }
    
    power[0] = 1;
    REP(i,N) power[i+1] = power[i] * g % N;
    
    cout << "YES" << endl;
    REP(i,N-1){
        int tmp = i;
        if(i % 2 == 0) tmp = N - 1 - tmp;
        printf("%d\n", (int)power[tmp]);
    }
    cout << N << endl;
    
    return 0;
}