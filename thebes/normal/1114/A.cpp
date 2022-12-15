#include <bits/stdc++.h>
using namespace std;

int a, b, c, x, y, z;

int main(){
    cin >> x >> y >> z >> a >> b >> c;
    int r = min(x, a);
    x -= r; a -= r;
    if(x) printf("NO\n");
    else{
        if(a+b>=y&&a+b+c>=y+z) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}