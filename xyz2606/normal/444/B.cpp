#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
vector<int> v;
int n, a[111111], b[111111], c[111111], cnt, o[111111];
bool cmp(int a, int b)
{
    return ::a[a] > ::a[b];
}
//x is 64-bit variable;
long long x;
long long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
int d;
void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
int main()
{
    cin >> n >> d >> x;
    initAB();
    for(int i = 0; i < n; i++) {c[i] = -1, o[i] = i; if(b[i]) v.push_back(i);}
    sort(o, o + n, cmp);
    cnt = n;
    for(int i = 0; i < n and cnt > sqrt(n); i++)
        for(int j = 0; j < (int)v.size(); j++)
        {
            if(c[o[i] + v[j]] == -1)
            {
                cnt--;
                c[o[i] + v[j]] = a[o[i]];
            }
        }
    for(int i = 0; i < n; i++) if(c[i] == -1)
    {
        c[i] = 0;
        for(int j = 0; j < (int)v.size() and i >= v[j]; j++) 
            c[i] = max(c[i], a[i - v[j]]);
    }
    for(int i = 0; i < n; i++) printf("%d\n", c[i]);
    fclose(stdin);
    return 0;
}