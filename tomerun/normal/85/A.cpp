#include <vector>
#include <list>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int N;
string line[4];

void solveEven(){
    for(int i = 0; i < N / 2; ++i) {
        line[0][2*i] = line[0][2*i+1] = i % 2 == 0 ? 'a' : 'c';
        line[1][2*i] = line[1][2*i+1] = i % 2 == 0 ? 'b' : 'd';
    }
    line[2][0] = line[3][0] = 'y';
    line[2][N-1] = line[3][N-1] = 'z';
    for(int i = 0; i < N / 2 - 1; ++i) {
        line[2][2*i+1] = line[2][2*i+2] = i % 2 == 0 ? 'e' : 'g';
        line[3][2*i+1] = line[3][2*i+2] = i % 2 == 0 ? 'f' : 'h';
    }
}

void solveOdd(){
    for(int i = 0; i < N / 2; ++i) {
        line[0][2*i] = line[0][2*i+1] = i % 2 == 0 ? 'a' : 'c';
        line[1][2*i] = line[1][2*i+1] = i % 2 == 0 ? 'b' : 'd';
    }
    line[0][N-1] = line[1][N-1] = 'z';
    line[2][0] = line[3][0] = 'y';
    for(int i = 0; i < N / 2; ++i) {
        line[2][2*i+1] = line[2][2*i+2] = i % 2 == 0 ? 'e' : 'g';
        line[3][2*i+1] = line[3][2*i+2] = i % 2 == 0 ? 'f' : 'h';
    }
}

int main()
{
    cin >> N;
    line[0].resize(N);
    line[1].resize(N);
    line[2].resize(N);
    line[3].resize(N);
    if(N%2 == 0){
        solveEven();
    }else{
        solveOdd();
    }
    for(int i = 0; i < 4; ++i) {
        cout << line[i] << endl;
    }
    return 0;
}