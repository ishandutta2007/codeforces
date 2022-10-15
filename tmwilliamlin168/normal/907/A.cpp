#include<vector>
#include<iostream>
#include<queue>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cmath>
#include<utility>
#include<list>
#include<set>
#include <string>
#include<map>
#define ll long long
#define ull unsigned long long
#define PI acos(-1.0)
#define inf 1<<30
#define EPS 1e-9
#define DI(n) int n;scanf("%d",&n)
#define DII(a,b) int a,b;scanf("%d %d",&a,&b)
#define DIII(a,b,c) int a,b,c;scanf("%d %d %d",&a,&b,&c)
using namespace std;
int main() {
	int V1, V2, V3, Vm;
	cin >> V1 >> V2 >> V3 >> Vm;
	int res1, res2, res3;
	if (Vm <= V3 && (2*Vm)>=V3) {
		res1 = 2 * V1;
		res2 = 2 * V2;
		res3 = V3;
		if ((2 * Vm) >= res1 || (2 * Vm) >= res2) {
			cout << -1 << endl;
		}
		else {
			cout << res1 << endl;
			cout << res2 << endl;
			cout << res3 << endl;
		}
	}
	else {
		int i;
		for (i = V3; i <= 2 * V3; i++) {
			if (Vm <= i && (2 * Vm) >= i) {
				res1 = 2 * V1;
				res2 = 2 * V2;
				res3 = i;
				if ((2 * Vm) >= res1 || (2 * Vm) >= res2) {
					cout << -1 << endl;
				}
				else {
					cout << res1 << endl;
					cout << res2 << endl;
					cout << res3 << endl;
				}
				break;
			}
		}
		if (i > (2 * V3)) {
			cout << -1 << endl;
		}
	}
	return 0;
}