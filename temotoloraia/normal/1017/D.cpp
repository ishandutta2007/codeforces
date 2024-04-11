#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N = (1<<12), M = 1e5+5;
int n, m, Q;
int w[100];
int A[N+5];
int s[N+5][N+5];
int main()
{
    n=12;
    cin>>n>>m>>Q;
    int nn = (1<<n);
    for (int i = 0; i < n; i++)
        cin>>w[i];
    while (m--){
        string S="";
        int x = 0;
        char ch;
        for (int i = n-1; i >= 0; i--){
            ch = getchar();
            while (ch!='0' && ch!='1')
                ch = getchar();
            S+=ch;
        }
        for (int i = S.size()-1; i >= 0; i--){
            x *= 2;
            x += S[i]-'0';
        }
        A[x]++;
    }
    for (int i = 0; i < nn; ++i){
        for (int j = 0; j < nn; ++j){
            int l = (i^j), x = 0;
            for (int k = 0; k < n && x <= 100; ++k)
                if ((l & (1<<k)) == 0)
                    x += w[k];
            if (x <= 100)
                s[i][x] += A[j];
        }
        for (int j = 1; j <= 100; j++)
            s[i][j] += s[i][j-1];
    }
    while (Q--){
        string S="";
        int x = 0;
        char ch;
        for (int i = n-1; i >= 0; i--){
            ch = getchar();
            while (ch!='0' && ch!='1')
                ch = getchar();
            S+=ch;
        }
        for (int i = S.size()-1; i >= 0; i--){
            x *= 2;
            x += S[i]-'0';
        }
        int k;
        scanf("%d",&k);
        printf ("%d\n",s[x][k]);
    }
    return 0;
}