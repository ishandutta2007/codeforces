#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, m, k;
    cin>>n;
    deque<int> odd;
    deque<int> even;
    for(int i =n-1; i > 0; i-=2) odd.push_back(i);
    for(int i =n-1; i > 0; i-=2) odd.push_front(i);
    even.push_back(n);
    for(int i =n-2; i > 0; i-=2) even.push_back(i);
    for(int i =n-2; i > 0; i-=2) even.push_front(i);
    printf("%d ", n);
    for(auto a: odd) printf("%d ", a);
    for(auto a: even) printf("%d ", a);
}