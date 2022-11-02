#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back

int T[100003], A[100003];

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    int n, m, w=0;
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", T+i);
    sort(T, T+m);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {scanf("%d", A+i); w+=A[i];}
    sort(A, A+n, cmp);
    for(int i=0; i+T[0]<n; i+=T[0]+2)
    {
        w-=A[i+T[0]];
        if(i+T[0]+1<n) w-=A[i+T[0]+1];
    }
    printf("%d\n", w);
    return 0;
}