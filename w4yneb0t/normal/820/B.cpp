#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cmath>

using namespace std;

typedef long long in;

int main(){
    in n,a;
    cin >> n >> a;
    double angle = (n-2)*180./n;
    double inc = angle/(n-2);
    double maxi = abs(angle-a);
    int curwh=3;
    int wh = 3;
    while(angle>=0){
        angle-=inc;
        curwh++;
        if(angle<=1e-9)
            break;
        if(maxi>abs(angle-a)){
            maxi=abs(angle-a);
            wh=curwh;
        }
    }
    cout << "1 2 " << wh << endl;
    return 0;
}