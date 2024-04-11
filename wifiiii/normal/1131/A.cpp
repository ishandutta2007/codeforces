#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod = 1e9+7;

int main()
{
    ll w1,h1,w2,h2;
    cin>>w1>>h1>>w2>>h2;
    ll s1 = (w1+2)*(h1+2), s2 = (w2+2)*(h2+2);
    ll lap = 2 * (2+min(w1, w2));
    cout << s1 + s2 - lap - w1*h1 - w2*h2 << endl;
}