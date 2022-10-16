#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
	cin >>a>>b>>c>>d;
	cout << 2-(a==c||b==d) << ' ' << ((a+b)%2==(c+d)%2)*(2-(a-b==c-d||a+b==c+d)) << ' ' << max(abs(c-a),abs(d-b));
}