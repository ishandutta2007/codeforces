#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m;
//    ll ans = 0;
    double l3,l4,l5;
    cin>>l3>>l4>>l5;
    double r3,r4,r5;
    double h3,h4,h5;
    double t3,t4,t5;
    double s3,s4,s5;
    r5 = l5/(2*sin(M_PI/5));
    r4 = l4/(2*sin(M_PI/4));
    r3 = l3/(2*sin(M_PI/3));
    h5 = sqrt(l5*l5 - r5*r5);
        h4 = sqrt(l4*l4 - r4*r4);
        h3 = sqrt(l3*l3 - r3*r3);
    t5 = r5 * cos(M_PI/5);
        t4 = r4 * cos(M_PI/4);
        t3 = r3 * cos(M_PI/3);
    s3=3*t3*l3/2;
        s4=4*t4*l4/2;
        s5=5*t5*l5/2;
    printf("%.10lf", (s3*h3+s4*h4+s5*h5)/3);
    

    
    

}