#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double ld;
#define pb push_back
ll k,a,b;
int main()
{
	cin>>k>>a>>b;
	ll sa=a/k,sb=b/k; a%=k, b%=k;
	if(b&&(!sa)) {puts("-1"); return 0;}
	if(a&&(!sb)) {puts("-1"); return 0;}
	cout<<sa+sb<<"\n";
}