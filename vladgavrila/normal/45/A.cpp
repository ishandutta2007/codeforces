#include <stdio.h>
#include <string>

using namespace std;

#define maxn 40

int n, i, j, k, nr;
const string x[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
string s;
char ch[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%s", ch);
    for(int i=0; ch[i]>='A'; ++i)
        s+=ch[i];
    scanf("%d", &nr);
    for(int i=0; i<12; ++i)
    {
        if(s==x[i])
        {
            k=i;
            break;
        }
    }
    k=(k+nr)%12;
    for(int i=0; i<x[k].size(); ++i)
    {
        printf("%c", x[k][i]);
    }
    printf("\n");

    return 0;
}