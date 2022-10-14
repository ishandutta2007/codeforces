#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int g,i,j,x1,x2,a1[1000050][27],a2[1000050][27];
long long m,n,rez;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    string s1,s2;
    cin >> m >> n;
    cin >> s1 >> s2;
    x1 = s1.size();
    x2 = s2.size();
    g = gcd(x1,x2);
    rez = 0;
    for (i = 0; i < x1; i++) 
        a1[i%g][s1[i]-(int)'a']++;
    for (i = 0; i < x2; i++) 
        a2[i%g][s2[i]-(int)'a']++;
    for (j = 0; j < 26; j++)
        for (i = 0; i < g; i++)
            rez += (long long)a1[i][j]*a2[i][j];
    long long lcm = (long long)x1*x2/gcd(x1,x2);
    rez = lcm - rez;
    rez *= (long long)m/(x2/g);
    cout << rez << endl;
    return 0;
}