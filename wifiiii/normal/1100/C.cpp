#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<set>
#include<cmath>
#include<stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mod = 1e9+7;
const double pi = 3.14159265358979;
int main()
{
    double n,r;
    cin>>n>>r;
    double theta = pi / n;
    cout << fixed << setprecision(8) << r*sin(theta)/(1-sin(theta)) << endl;
}